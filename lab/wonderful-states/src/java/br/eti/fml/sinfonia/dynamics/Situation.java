package br.eti.fml.sinfonia.dynamics;

import br.eti.fml.wonderfulstates.changing.Event;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Situation {
    private Condition condition;
    private Map<String, Boolean> eventsConditions;

    /**
     *
     * @param condition
     * @param eventsConditions at least one of them
     */
    public Situation(Condition condition, EventCondition ... eventsConditions) {
        this.condition = condition;
        this.eventsConditions = new HashMap<String, Boolean>();

        for (EventCondition ec : eventsConditions) {
            this.eventsConditions.put(ec.getHash(), Boolean.TRUE);
        }
    }

    public String[] getHashs() {
        return this.eventsConditions.keySet().toArray(new String[0]);
    }

    public boolean isHappening(Event event) {
        if (eventsConditions.containsKey(
                new EventCondition(event, EventCondition.Level.ACTION_HASH).getHash())
            || eventsConditions.containsKey(
                new EventCondition(event, EventCondition.Level.ACTION_TYPE).getHash())
            || eventsConditions.containsKey(
                new EventCondition(event, EventCondition.Level.THE_SAME).getHash()))
        {
            if (this.condition.isTrue()) {
                return true;
            }
        }

        return false;
    }
}
