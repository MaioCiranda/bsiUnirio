public class ContatoEmergencia extends ContatoBase{
    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }

    @Override
    boolean setNome(String nome) {
        this.nome = nome;
        return false;
    }
}
