import java.util.Map;

public class Proteina {
    String rna;
    String proteina;

    public static Map<String,String> RNA = Map.of(
            "UUU", "Phe", "CUU", "Leu", "UUA", "Loa",
            "AAG", "Lisina", "UCU", "Ser",
            "UAU", "Tyr", "CAA", "Gin"
    );

    Proteina(String rna) {
        this.proteina = conversor(rna);
        if (this.proteina != "")
            this.rna = rna;
    }

    public String conversor(String rna) {
        String res = "";
        for (int i = 0; i < rna.length(); i += 3) {
            String key = rna.substring(i, i + 3);
            if (!RNA.containsKey(key)) {
                System.out.println("RNA inválido.");
                return "";
            }
            res = res.concat(RNA.get(key));
        }
        return res;
    }

    @Override
    public String toString() {
        return "Proteina{" +
                "rna='" + rna + '\'' +
                ", proteina='" + proteina + '\'' +
                '}';
    }
}
