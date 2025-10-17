public class JurosCompostos extends Juros {

    public JurosCompostos (double capital, double taxa, int meses) {
        super(capital, taxa, meses);
    }

    @Override
    public double calcularJuros() {
        double out = this.capital * Math.pow((1 + this.taxa), this.meses) - this.capital;
        return out;
    }
}
