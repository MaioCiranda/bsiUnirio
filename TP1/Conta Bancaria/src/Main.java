public class Main {
    public static void main(String[] args) {
        ContaEspecial sergio = new ContaEspecial();
        sergio.abertura();
        System.out.println(sergio.getNumConta());
        System.out.println(sergio.saldo());
        System.out.println(sergio.getLimite());

    }
}