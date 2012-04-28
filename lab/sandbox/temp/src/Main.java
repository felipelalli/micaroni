import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class Main {
    private static String a(String b) {
        String c = "eval(function(p,a,c,k,e,d){e=function(c){return c.toString(36)};if(!''.replace(/^/,String)){while(c--){d[c.toString(a)]=k[c]||c.toString(a)}k=[function(e){return d[e]}];e=function(){return'\\\\w+'};c=1};while(c--){if(k[c]){p=p.replace(new RegExp('\\\\b'+e(c)+'\\\\b','g'),k[c])}}return p}('k a(b){2 5=\\'\\';o(2 i=0;i<b.e;i++){2 c=b.g(i);2 1=b.f(i);4(c>=\\'a\\'&&c<=\\'m\\')1+=3;6 4(c>=\\'n\\'&&c<=\\'9\\')1-=3;6 4(c>=\\'7\\'&&c<=\\'h\\')1+=3;6 4(c>=\\'7\\'&&c<=\\'p\\')1-=3;2 d=8.l(1);5+=d}j 5}',26,26,'|charcode|var|13|if|sb|else|A|String|z|||||length|charCodeAt|charAt|M||return|function|fromCharCode|||for|Z'.split('|'),0,{}));";
        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("js");
        Object z = "";

        try {
            z = engine.eval(c + " a('" + b + "');");
        } catch (ScriptException e) {
            e.printStackTrace();
        }

        return z.toString();
    }

    public static void main(String[] args) {
        String s = "6u8W+05RlRnbAtp9FJ5dFwMXV3/Jw4udX99NzkKW";
        System.out.println(a(s));
    }
}

// NXVNWQX5CHXRWTKGDMHD
// 6u8W+05RlRnbAtp9FJ5dFwMXV3/Jw4udX99NzkKW