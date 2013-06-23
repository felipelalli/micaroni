package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class RulesOverTime {
    private String code;
    private Long seed;
    private Long version;
    private Long secondCycleBegin;
    private Long secondCycleEnd;
    private Phenotype initialState;

    public String getCode() {
        return code;
    }

    public Long getSeed() {
        return seed;
    }

    /**
     * Starts with 0 and continues to 1, 2, 3... to infinite
     */
    public Long getVersion() {
        return version;
    }

    /**
     * Starts with 0 and continues to 1, 2, 3... to {@link #getSecondCycleEnd()}
     */
    public Long getSecondCycleBegin() {
        return secondCycleBegin;
    }

    /**
     * The last second this {@link RulesOverTime} can be applied to
     */
    public Long getSecondCycleEnd() {
        return secondCycleEnd;
    }

    public Phenotype getInitialState() {
        return initialState;
    }
}
