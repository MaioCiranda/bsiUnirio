public class Juros {
    protected double juros;
    protected double capital = 0;
    protected double taxa = 0;
    protected int meses = 0;

    public Juros (double capital, double taxa, int meses) {
        setCapital(capital);
        setTaxa(taxa);
        setMeses(meses);
        setJuros();
    }

    public void setCapital(double capital) {
        if (capital > 0) {
            this.capital = capital;
            setJuros();
        }
        else
            System.out.println("Capital inválido");
    }

    public double getCapital() {
        return capital;
    }

    public void setTaxa(double taxa) {
        if (taxa > 0) {
            this.taxa = taxa / 100;
            setJuros();
        }
        else System.out.println("Taxa inválida.");
    }

    public double getTaxa() {
        return taxa;
    }

    public void setMeses(int meses) {
        if (meses > 0) {
            this.meses = meses;
            setJuros();
        }
        else
            System.out.println("Tempo inválido.");
    }

    public int getMeses() {
        return meses;
    }

    private void setJuros() {
        if (this.capital > 0 && this.taxa > 0 && this.meses > 0)
            this.juros = calcularJuros();
    }

    public double getJuros() {
        return juros;
    }

    public double calcularJuros() {
        return 0;
    }
}
