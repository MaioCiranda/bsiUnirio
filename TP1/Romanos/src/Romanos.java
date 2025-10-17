import java.util.Map;
public class Romanos {
    public static Map<Integer, String> UNIDADES = Map.of(
            0, "", 1, "I", 2, "II", 3, "III",
            4, "IV", 5, "V", 6, "VI",
            7, "VII", 8, "VIII", 9, "IX"
    );

    public static Map<Integer, String> DEZENAS = Map.of(
            0, "", 1, "X", 2, "XX", 3, "XXX",
            4, "XL", 5, "L", 6, "LX",
            7, "LXX", 8, "LXXX", 9, "XC"
    );

    public static Map<Integer, String> CENTENAS = Map.of(
            0, "", 1, "C", 2, "CC", 3, "CCC",
            4, "CD", 5, "D", 6, "DC", 7,
            "DCC", 8, "DCCC", 9, "CM"
    );

    public static String conversao (int numero) {
        int centenas = numero / 100;
        int dezenas = (numero % 100) / 10;
        int unidades = numero % 10;
        String res = "";
        res = res.concat(CENTENAS.get(centenas));
        res = res.concat(DEZENAS.get(dezenas));
        res = res.concat(UNIDADES.get(unidades));
        return res;
    }
}
