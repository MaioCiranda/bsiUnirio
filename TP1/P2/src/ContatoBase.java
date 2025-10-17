import java.util.Comparator;
abstract class ContatoBase {
    String nome;
    int telefone;

    abstract boolean setNome(String nome);
    Comparator<ContatoBase> comparador = new Comparator<ContatoBase>() {
        @Override
        public int compare(ContatoBase o1, ContatoBase o2) {
            return 0;
        }
    };

    @Override
    public String toString() {
        return "ContatoBase{" +
                "nome='" + nome + '\'' +
                ", telefone='" + telefone + '\'' +
                '}';
    }
}
