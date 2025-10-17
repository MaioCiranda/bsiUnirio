public class Estagiario extends Funcionario {

    public Estagiario(String nome, float salarioBruto) {
        super(nome, salarioBruto);
    }

    @Override
    public float salarioLiquido() {
        return this.getSalarioBruto();
    }
}
