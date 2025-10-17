public class Empregado extends MembroDaComunidade{
    double salario;
    int horasTrabalho;
    int anoDeContratacao;

    @Override
    public String toString() {
        return  super.toString() +
                "salario: " + salario +
                "\nhorasTrabalho: " + horasTrabalho +
                "\nanoDeContratacao: " + anoDeContratacao +
                "\n";
    }
}
