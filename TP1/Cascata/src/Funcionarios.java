public class Funcionarios extends Empregado{
    String setor;
    String funcao;
    boolean noturno;

    @Override
    public String toString() {
        return super.toString() +
                "setor: '" + setor + '\'' +
                "\nfuncao: '" + funcao + '\'' +
                "\nnoturno: " + noturno +
                "\n";
    }
}
