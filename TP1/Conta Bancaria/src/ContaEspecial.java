import java.util.Scanner;
public class ContaEspecial extends ContaComum implements Rendimento {
    private double limite;
    private double juros;

    public void rendimento() {
        if (this.saldo < 0)
            this.saldo += this.saldo * juros;
    }

    @Override
    public boolean abertura() {
        Scanner teclado = new Scanner(System.in);
        super.abertura();
        System.out.print("Limite: ");
        double limit = teclado.nextDouble();
        setLimite(limit);
        System.out.print("Saldo: ");
        double valor = teclado.nextDouble();
        setSaldo(valor);
        if (this.saldo != 0 && this.limite != 0)
            return true;
        else
            return false;
    }

    public ContaEspecial(int numero, double saldo, String titular, double limite) {
        super(numero, saldo, titular);
        setLimite(limite);
    }

    public ContaEspecial() {
        super();
    }

    public void setJuros(double juros) {
        if (juros > 0)
            this.juros = juros / 100;
    }

    public double getJuros() {
        return juros;
    }

    @Override
    public void setSaldo(double saldo) {
        if (saldo >= -this.limite)
            this.saldo = saldo;
        else
            System.out.println("Saldo inválido.");
    }

    public void setLimite(double limite) {
        if (limite > 0)
            this.limite = limite;
        else
            System.out.println("Limite inválido.");
    }

    public double getLimite() {
        return limite;
    }

    @Override
    public void saque(double saque) {
        if (saque <= 0)
            System.out.println("Saque inválido.");
        else if (saque <= saldo)
            this.saldo -= saque;
        else if (saque <= saldo + limite)
            saldo -= saque;
        else
            System.out.println("Saque inválido.");
    }
}
