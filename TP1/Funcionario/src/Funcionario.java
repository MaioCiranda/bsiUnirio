public class Funcionario {
    String nome;
    protected float salarioBruto;
    protected float salarioLiquido;

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setSalarioBruto(float salarioBruto) {
        if (salarioBruto >= 0)
            this.salarioBruto = salarioBruto;
        else
            System.out.println("Sálario inválido.");
    }

    public void setSalarioLiquido() {
        this.salarioLiquido = salarioLiquido();
    }

    Funcionario(String nome, float salarioBruto) {
        setNome(nome);
        setSalarioBruto(salarioBruto);
        setSalarioLiquido();
    }

    public String getNome() {
        return nome;
    }

    public float getSalarioBruto() {
        return salarioBruto;
    }

    public float getSalarioLiquido() {
        return salarioLiquido;
    }

    public float salarioLiquido() {
        if (salarioBruto <= 900)
            return salarioBruto;
        if (salarioBruto <= 1500)
            return salarioBruto * 0.85F;
        return salarioBruto * 0.8F;
    }
}
