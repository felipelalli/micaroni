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

package br.eti.fml.storage;

import java.io.Serializable;

/**
 * It represents some key-value implementation.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface SomeKeyValueImplementation {
    public void saveString(String key, String value) throws SomeDirtyError;
    public String retrievesString(String key) throws SomeDirtyError;

    public void saveInteger(String key, Integer value) throws SomeDirtyError;
    public Integer retrievesInteger(String key) throws SomeDirtyError;

    public <T extends Serializable> void saveGeneric(String key, T value) throws SomeDirtyError;
    public <T extends Serializable> T retrievesGeneric(String key) throws SomeDirtyError;

    public String getDataBaseUID();

    /**
     * After a shutdown it can't back again in the same instance.
     */
    public void shutdown() throws SomeDirtyError;
}
