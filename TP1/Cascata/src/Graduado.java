public class Graduado extends MembroDaComunidade{
    String matricula;
    String curso;
    String dataGraduacao;

    @Override
    public String toString() {
        return  super.toString() +
                "matricula: '" + matricula + '\'' +
                "\ncurso: '" + curso + '\'' +
                "\ndataGraduacao: '" + dataGraduacao + '\'' + "\n";
    }
}
