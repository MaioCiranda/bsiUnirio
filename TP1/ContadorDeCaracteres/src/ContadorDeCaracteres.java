import java.util.HashMap;
import java.util.Map;

import static java.util.Map.entry;

public class ContadorDeCaracteres {

    private static void popularMapa(HashMap<Character, Integer> mapa) {
        for (char c = ' '; c <= 'ỿ'; c++) {
            mapa.put(c, 0);
        }
    }
    public static void contarCaracteres(String frase){
        HashMap<Character, Integer> CARACTERES = new HashMap<>();
        popularMapa(CARACTERES);
        char[] charr = frase.toCharArray();

        for (int i = 0; i < charr.length; i++) {
            Character comp = Character.toUpperCase(charr[i]);
            if (CARACTERES.containsKey(comp))
                CARACTERES.merge(comp, 1, Integer::sum);
            }
        printarMapa(CARACTERES);
    }

    protected static void printarMapa(HashMap<Character, Integer> mapa) {
        for (Character c = ' '; c <= 'ỿ'; c++) {
            if (mapa.get(c) > 0)
                System.out.printf("%c: %d\n", c, mapa.get(c));
        }
    }
}
