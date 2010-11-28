/*
 * Copyright (c) 2010.
 * CC-by Felipe Micaroni Lalli <micaroni@gmail.com>
 * Special thanks to Igor Hjelmstrom Vinhas Ribeiro <igorhvr@iasylum.net>
 */

package br.eti.fml.stonerlmg.test;

import br.fml.eti.machinegun.DirtyWork;
import br.fml.eti.machinegun.auditorship.ArmyAudit;

import java.util.Random;

/**
 * Simulate a Integer processing using a random sleep of 0 to 2 millis. 
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 *         Nov 15, 2010 6:54:17 PM
 */
public class ProcessIntegerSlowly implements DirtyWork<Integer> {
    private Random random = new Random();

    @Override
    public void workOnIt(long jobId, String consumerName,
                         ArmyAudit audit, Integer dataToBeProcessed) {

        Integer time = random.nextInt(2);
        System.out.println("*** Will process " + dataToBeProcessed
                + " for " + time + " millis...");

        try {
            Thread.sleep(time);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        TestHornetQ.processed(dataToBeProcessed);

        System.out.println("*** " + dataToBeProcessed + " was processed!!");
        audit.aConsumerHasBeenFinishedHisJob(jobId, consumerName, true, null, "OK!");
    }
}
