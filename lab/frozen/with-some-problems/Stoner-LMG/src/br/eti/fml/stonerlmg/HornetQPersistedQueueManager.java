/*
 * Copyright (c) 2010.
 * CC-by Felipe Micaroni Lalli <micaroni@gmail.com>
 * Special thanks to Igor Hjelmstrom Vinhas Ribeiro <igorhvr@iasylum.net>
 */

package br.eti.fml.stonerlmg;

import br.fml.eti.machinegun.auditorship.ArmyAudit;
import br.fml.eti.machinegun.externaltools.Consumer;
import br.fml.eti.machinegun.externaltools.PersistedQueueManager;
import org.hornetq.api.core.SimpleString;
import org.hornetq.api.core.TransportConfiguration;
import org.hornetq.api.core.client.ClientConsumer;
import org.hornetq.api.core.client.ClientMessage;
import org.hornetq.api.core.client.ClientProducer;
import org.hornetq.api.core.client.ClientSession;
import org.hornetq.api.core.client.ClientSessionFactory;
import org.hornetq.api.core.client.HornetQClient;
import org.hornetq.api.core.client.MessageHandler;
import org.hornetq.core.config.Configuration;
import org.hornetq.core.config.impl.ConfigurationImpl;
import org.hornetq.core.remoting.impl.invm.InVMAcceptorFactory;
import org.hornetq.core.remoting.impl.invm.InVMConnectorFactory;
import org.hornetq.core.remoting.impl.netty.NettyAcceptorFactory;
import org.hornetq.core.server.JournalType;
import org.hornetq.core.server.impl.HornetQServerImpl;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.concurrent.Semaphore;

/**
 * HornetQ implementation of
 * {@link br.fml.eti.machinegun.externaltools.PersistedQueueManager}.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 *         Nov 21, 2010 3:23:28 AM
 */
public class HornetQPersistedQueueManager implements PersistedQueueManager {
    private HornetQServerImpl server;
    private boolean end = false;

    private Map<String, ClientSessionFactory> clientSessionFactories
            = new HashMap<String, ClientSessionFactory>();

    private Semaphore semaphore = new Semaphore(1);
    private Map<String, Semaphore> consumers = new HashMap<String, Semaphore>();
    private boolean waitForEmptyQueueWhenKillConsumers = false;

    public HornetQPersistedQueueManager(boolean waitForEmptyQueueWhenKillConsumers) throws Exception {
        this.waitForEmptyQueueWhenKillConsumers = waitForEmptyQueueWhenKillConsumers;

        Configuration config = new ConfigurationImpl();
        HashSet<TransportConfiguration> transports = new HashSet<TransportConfiguration>();
        transports.add(new TransportConfiguration(NettyAcceptorFactory.class.getName()));
        transports.add(new TransportConfiguration(InVMAcceptorFactory.class.getName()));

        config.setAcceptorConfigurations(transports);
        config.setJournalType(JournalType.NIO);
        config.setSecurityEnabled(false);
        config.setLargeMessagesDirectory("data");
        config.setMessageCounterEnabled(true);

        this.server = new HornetQServerImpl(config);
        this.server.start();
    }

    private ClientSessionFactory getSessionFactory(String queueName) throws Exception {
        
        try {
            semaphore.acquire();

            if (!this.clientSessionFactories.containsKey(queueName)) {
                ClientSessionFactory nettyFactory
                        = HornetQClient.createClientSessionFactory(
                                new TransportConfiguration(
                                        InVMConnectorFactory.class.getName()));

                this.server.deployQueue(new SimpleString(queueName),
                        new SimpleString(queueName), null, true, false);

                this.clientSessionFactories.put(queueName, nettyFactory);
            }

            return this.clientSessionFactories.get(queueName);
        } finally {
            semaphore.release();
        }
    }

    @Override
    public void putIntoAnEmbeddedQueue(ArmyAudit armyAudit,
            String queue, byte[] bytes) throws InterruptedException {

        if (this.end) {
            armyAudit.errorWhenPuttingIntoAnEmbeddedQueue(
                    new InterruptedException("The queue "
                            + queue + " is already down!"));
        } else {
            try {
                ClientSession session = getSessionFactory(queue).createSession();
                ClientProducer producer = session.createProducer(queue);
                ClientMessage message = session.createMessage(true);
                ByteArrayInputStream byteArrayInputStream
                        = new ByteArrayInputStream(bytes);

                message.setBodyInputStream(byteArrayInputStream);
                producer.send(message);
                session.commit();
                session.close();
            } catch (Exception e) {
                armyAudit.errorWhenPuttingIntoAnEmbeddedQueue(e);
            }
        }
    }

    @Override
    public void registerANewConsumerInAnEmbeddedQueue(
            final ArmyAudit armyAudit, final String queue,
            final Consumer consumer) {

        new Thread() {
            public void run() {
                Semaphore semaphore = new Semaphore(0);
                consumers.put(queue, semaphore);

                try {
                    ClientSession session = getSessionFactory(queue).createSession();
                    ClientConsumer clientConsumer = session.createConsumer(queue);
                    session.start();

                    clientConsumer.setMessageHandler(new MessageHandler() {
                        @Override
                        public void onMessage(ClientMessage clientMessage) {
                            ByteArrayOutputStream byteArrayOutputStream
                                    = new ByteArrayOutputStream();

                            try {
                                clientMessage.saveToOutputStream(byteArrayOutputStream);
                                consumer.consume(byteArrayOutputStream.toByteArray());
                            } catch (Exception e) {
                                armyAudit.errorWhenRegisteringANewConsumerInAnEmbeddedQueue(e);
                            }
                        }
                    });

                    semaphore.acquire();

                    session.stop();
                    session.close();

                } catch (Exception e) {
                    armyAudit.errorWhenRegisteringANewConsumerInAnEmbeddedQueue(e);
                }
            }
        }.start();
    }

    @Override
    public void killAllConsumers(String queueName) throws InterruptedException {
        end = true;
/* FIXME
        if (this.waitForEmptyQueueWhenKillConsumers) {
            try {
                ClientSession session = getSessionFactory(queueName).createSession();
                ClientSession.QueueQuery q = session.queueQuery(
                        new SimpleString(queueName));

                while (q.getMessageCount() > 0) {
                    System.out.println(queueName + ": " + q.getMessageCount());
                    Thread.sleep(1000);
                    q = session.queueQuery(new SimpleString(queueName));
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
*/
        consumers.get(queueName).release();
    }

    public void shutdown() throws Exception {
        this.server.stop();
    }
}
