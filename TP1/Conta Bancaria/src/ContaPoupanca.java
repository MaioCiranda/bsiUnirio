public class ContaPoupanca extends ContaComum implements Rendimento{
    static double rendimento = 0.5;

    @Override
    public void rendimento() {
        this.saldo += saldo * rendimento;
    }

    @Override
    public boolean abertura() {
        return super.abertura();
    }

    @Override
    public boolean abertura(double valor) {
        return super.abertura(valor);
    }

    public ContaPoupanca(int numero, double saldo, String titular) {
        super(numero, saldo, titular);
    }

}
