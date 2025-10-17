public class MembroDaComunidade {
    String nome;
    String cpf;
    String email;

    @Override
    public String toString() {
        return "nome: '" + nome + '\'' +
                "\ncpf: '" + cpf + '\'' +
                "\nemail: '" + email + '\'' + "\n";
    }
}
