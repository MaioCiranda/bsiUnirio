public class CorpoDocente extends Empregado{
    String departamento;
    boolean possuiDoutorado;
    int anosExperiencia;

    @Override
    public String toString() {
        return super.toString() +
                "departamento: '" + departamento + '\'' +
                "\npossuiDoutorado: " + possuiDoutorado +
                "\nanosExperiencia: " + anosExperiencia +
                "\n";
    }
}
