//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Estagiario toto = new Estagiario("Totó", 2000);
        System.out.println(toto.getNome());
        System.out.println(toto.getSalarioBruto());
        System.out.println(toto.getSalarioLiquido());
    }
}