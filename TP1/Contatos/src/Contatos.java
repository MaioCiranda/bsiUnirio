import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Contatos {
    public static Map<String, String> CONTATOS = new HashMap<>();

    public static void AdicionarContatos() {
        Scanner teclado = new Scanner(System.in);
        for (;;) {
            String nome;
            String numero = "";
            System.out.print("Nome: ");
            nome = teclado.nextLine();
            if (nome.isEmpty())
                break;
            while (!numero.replaceAll("[0-9()\\-]", "").isEmpty() ||
                    numero.isEmpty()) {
                System.out.print("Número: ");
                numero = teclado.nextLine();
            }
            CONTATOS.put(nome, numero);
        }
        printarContatos();
    }

    public static void printarContatos () {
        StringBuilder sb = new StringBuilder("Contatos: \n");
        CONTATOS.forEach((key, value) ->
                sb.append(key).append(": ").append(value).append("\n")
        );
        System.out.println(sb.toString());
    }
}
