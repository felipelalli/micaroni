package br.eti.fml.joelingo.timeagent;

import br.eti.fml.joelingo.JsonCapable;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public final class AgentType extends JsonCapable<AgentType> {
    private final String uuid;
    private final String name;
    private final String description;
    private final Long version;
    private final boolean accessory;

    private final String onCycleCode;

    /**
     *
     * @param uuid an unique id
     * @param name name of this modifier
     * @param description description of this modifier
     * @param version version of this modifier
     * @param accessory if this modifier is an accessory it can be removed
     * @param onAttachCode what happens when this modifier is attached to a joelingo
     * @param onCycleCode what happens each second
     * @param onRemoveCode what happens when this modifier is removed from a joelingo
     */
    public AgentType(String uuid, String name,
                     String description,
                     Long version,
                     boolean accessory,
                     String onAttachCode,
                     String onCycleCode,
                     String onRemoveCode) {

        this.uuid = uuid;
        this.name = name;
        this.description = description;
        this.version = version;
        this.accessory = accessory;
        this.onCycleCode = onCycleCode;
    }

    public String getUuid() {
        return uuid;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public Long getVersion() {
        return version;
    }

    public String getOnCycleCode() {
        return onCycleCode;
    }

    public boolean isAccessory() {
        return accessory;
    }
}
