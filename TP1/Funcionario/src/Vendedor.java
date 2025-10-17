public class Vendedor extends Funcionario {
    private float bonus;

    public Vendedor(String nome, float salarioBruto, float bonus) {
        super(nome, salarioBruto);
        setBonus(bonus);
        setSalarioLiquido();
    }

    public void setBonus(float bonus) {
        if (bonus >= 0)
            this.bonus = bonus;
        else
            System.out.println("Bônus inválido.");
    }

    public float getBonus() {
        return bonus;
    }

    @Override
    public float salarioLiquido() {
        System.out.println(getSalarioBruto() + bonus);
        if (getSalarioBruto() + bonus <= 900)
            return getSalarioBruto() + bonus;
        if (getSalarioBruto() + bonus <= 1500)
            return (getSalarioBruto() + bonus) * 0.85F;
        return (getSalarioBruto() + bonus) * 0.8F;
    }
}
