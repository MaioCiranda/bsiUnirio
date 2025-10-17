public class Aluno extends MembroDaComunidade{
    String matricula;
    String curso;
    float cr;

    @Override
    public String toString() {
        return  super.toString() +
                "matricula: '" + matricula + '\'' +
                "\ncurso: '" + curso + '\'' +
                "\ncr: " + cr +
                "\n";
    }
}
