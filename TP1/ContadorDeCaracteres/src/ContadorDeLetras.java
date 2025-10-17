import java.util.HashMap;
import java.util.Map;
import static java.util.Map.entry;

public class ContadorDeLetras {
    private static Map<Character, Integer> LETRASBASE = Map.ofEntries(
            entry('A', 0), entry('B', 0), entry('C', 0), entry('D', 0), entry('E', 0),
            entry('F', 0), entry('G', 0), entry('H', 0), entry('I', 0), entry('J', 0),
            entry('K', 0), entry('L', 0), entry('M', 0), entry('N', 0), entry('O', 0),
            entry('P', 0), entry('Q', 0), entry('R', 0), entry('S', 0), entry('T', 0),
            entry('U', 0), entry('V', 0), entry('W', 0), entry('X', 0), entry('Y', 0),
            entry('Z', 0)
    );

    public static void contarCaracteres(String frase) {
        HashMap<Character, Integer> LETRAS = new HashMap<>(LETRASBASE);
        char[] charr = frase.toCharArray();

        for (int i = 0; i < charr.length; i++) {
            Character comp = Character.toUpperCase(charr[i]);

            if (Character.isAlphabetic(comp)) {
                if (LETRAS.containsKey(comp))
                    LETRAS.merge(comp, 1, Integer::sum);
                else
                {
                    if (comp.toString().replaceAll("[ÁÀÂÃÄÅĀ]", "").isEmpty())
                        LETRAS.merge('A', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÉÈÊËĒ]", "").isEmpty())
                        LETRAS.merge('E', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÍÌÎÏĪ]", "").isEmpty())
                        LETRAS.merge('I', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÓÒÔÕÖØŌ]", "").isEmpty())
                        LETRAS.merge('O', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÚÙÛÜŪ]", "").isEmpty())
                        LETRAS.merge('U', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÇĆĈĊČ]", "").isEmpty())
                        LETRAS.merge('C', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÐĎĐ]", "").isEmpty())
                        LETRAS.merge('D', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ĹĻĽŁ]", "").isEmpty())
                        LETRAS.merge('L', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ÑŃŅŇ]", "").isEmpty())
                        LETRAS.merge('N', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ŚŜŞŠ]", "").isEmpty())
                        LETRAS.merge('S', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ŔŖŘ]", "").isEmpty())
                        LETRAS.merge('R', 1, Integer::sum);
                    else if (comp.toString().replaceAll("[ŹŻŽ]", "").isEmpty())
                        LETRAS.merge('Z', 1, Integer::sum);
                }
            }
        }
        printarMapa(LETRAS);
    }

    protected static void printarMapa(HashMap<Character, Integer> mapa) {
        for (Character c = 'A'; c <= 'Z'; c++) {
            if (mapa.get(c) > 0)
                System.out.printf("%c: %d\n", c, mapa.get(c));
        }
    }
}
