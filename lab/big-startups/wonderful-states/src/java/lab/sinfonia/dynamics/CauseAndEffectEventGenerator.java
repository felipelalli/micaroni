/*
 * Copyright (c) 2010.
 * Wonderful States
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0
 * Unported License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 171 Second Street, Suite 300,
 * San Francisco, California, 94105, USA.
 */

package br.eti.fml.sinfonia.dynamics;

import br.eti.fml.basic.Pair;
import br.eti.fml.wonderfulstates.StateException;
import br.eti.fml.wonderfulstates.changing.Event;
import br.eti.fml.wonderfulstates.changing.MutableState;
import br.eti.fml.wonderfulstates.conducting.Key;
import br.eti.fml.wonderfulstates.conducting.SecurityGuardOfStates;
import br.eti.fml.wonderfulstates.dynamics.EventGenerator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Generates {@link br.eti.fml.wonderfulstates.mutable.Event}s
 * depending of {@link Situation}s.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class CauseAndEffectEventGenerator extends EventGenerator {
    private Map<String, Pair<Situation, Event[]>> causeAndEffects;
    private List<Event> events;

    public CauseAndEffectEventGenerator() {
        this.causeAndEffects = new HashMap<String, Pair<Situation, Event[]>>();
        this.events = Collections.synchronizedList(new ArrayList<Event>());
    }

    public void addCauseAndEffect(
            Situation inSituation, Event ... eventsToThrow)
    {
        for (String hash : inSituation.getHashs()) {
            causeAndEffects.put(hash, new
                    Pair<Situation, Event[]>(inSituation, eventsToThrow));
        }
    }

    @Override
    public void itHappened(Event event) {
        this.events.add(event);
    }

    @Override
    public void executePendingTasks(
            SecurityGuardOfStates groupOfStatesToManipulate) throws InterruptedException
    {
        List<Event> processedEvents = new ArrayList<Event>();

        for (Event event : this.events) {
            String key1 = new EventCondition(event,
                    EventCondition.Level.ACTION_HASH).getHash();

            String key2 = new EventCondition(event,
                    EventCondition.Level.ACTION_TYPE).getHash();

            String key3 = new EventCondition(event,
                    EventCondition.Level.THE_SAME).getHash();

            Pair<Situation, Event[]> effect = null;

            if (causeAndEffects.containsKey(key1)) {
                effect = causeAndEffects.get(key1);
            } else if (causeAndEffects.containsKey(key2)) {
                effect = causeAndEffects.get(key2);
            } else if (causeAndEffects.containsKey(key3)) {
                effect = causeAndEffects.get(key3);
            }

            if (effect != null) {
                if (effect.car.isHappening(event)) {
                    Pair<Key, MutableState> pair
                            = groupOfStatesToManipulate
                            .getAndBlockStateToChange(event.getRelatedState());

                    try {
                        pair.cdr.apply(pair.cdr.getValue(), event);
                        processedEvents.add(event);
                    } catch (StateException e) {
                        System.err.println("Sinfonia: Ignoring " + e);
                        break;
                    } finally {
                        groupOfStatesToManipulate.unblockState(pair.car);
                    }
                }
            }
            
            this.events.removeAll(processedEvents);
        }
    }
}
