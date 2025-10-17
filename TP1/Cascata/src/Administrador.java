public class Administrador extends CorpoDocente{
    String cargo;
    double orcamentoAnual;
    int nivelAcesso;

    @Override
    public String toString() {
        return super.toString() +
                "cargo: " + cargo + '\'' +
                "\norcamentoAnual: " + orcamentoAnual +
                "\nnivelAcesso: " + nivelAcesso +
                "\n";
    }
}
