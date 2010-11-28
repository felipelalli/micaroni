package br.eti.fml.basic;

/**
 *
 * @author felipelalli
 */
public class CreationError extends RuntimeException  {
    public CreationError(Throwable e) {
        super(e);
    }

    public CreationError() {
        super();
    }

    public CreationError(String msg) {
        super(msg);
    }

    public CreationError(String msg, Throwable e) {
        super(msg, e);
    }

    @Override
    public String toString() {
        String error = "Error " + this.getMessage();
        
        if (this.getCause() != null) {
            error += " caused by " + this.getCause();
        }
        
        return error;
    }
}
