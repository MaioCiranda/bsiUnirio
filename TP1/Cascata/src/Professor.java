public class Professor extends CorpoDocente{
    String disciplinaPrincipal;
    int qtdTurmas;
    boolean orientador;

    @Override
    public String toString() {
        return super.toString() +
                "disciplinaPrincipal: " + disciplinaPrincipal + '\'' +
                "\nqtdTurmas: " + qtdTurmas +
                "\norientador: " + orientador +
                "\n";
    }
}
