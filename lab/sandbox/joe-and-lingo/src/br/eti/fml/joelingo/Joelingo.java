package br.eti.fml.joelingo;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo {
    private Genotype genotype;
    private Phenotype phenotype;

    private Long currentSecondCycle;

    private Queue<ExternalAction> actions = new ArrayDeque<>(10);

    public void arises() {
        // TODO: copy genotype characteristics to phenotype
    }

    public OneSecondLifeResult liveOneSecond(RulesOverTime rulesOverTime,
                                             ExternalAction ... externalActions) {
        //actions.poll();

        return null;
    }

    public void makesPuppy(Joelingo joelingo) {
        actions.offer(new ExternalAction(Action.MAKES_PUPPY));
    }

    public void fightWith(Joelingo ... joelingo) {
        actions.offer(new ExternalAction(Action.FIGHT));
    }
}

