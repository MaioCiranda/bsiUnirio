public class JurosSimples extends Juros {

    public JurosSimples (double capital, double taxa, int meses) {
        super(capital, taxa, meses);
    }

    @Override
    public double calcularJuros() {
        double out = this.capital * this.taxa * this.meses;
        return out;
    }
}