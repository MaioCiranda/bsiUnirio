import java.util.Scanner;
public class ContaComum {
    protected int numConta;
    protected double saldo;
    protected String titular;

    public ContaComum(int numero, double saldo, String titular) {
        setNumConta(numero);
        setSaldo(saldo);
        setTitular(titular);
    }
    public ContaComum() {

    };

    public boolean abertura() {
        Scanner teclado = new Scanner(System.in);
        System.out.print("Nome do titular: ");
        String nome = teclado.nextLine();
        setTitular(nome);
        System.out.print("Número da conta: ");
        int numero = teclado.nextInt();
        setNumConta(numero);
        setSaldo(0);
        if (this.numConta > 0)
            return true;
        else
            return false;
    }

    public boolean abertura(double valor) {
        abertura();
        setSaldo(valor);
        if (Math.abs(this.saldo) == this.saldo)
            return true;
        else
            return false;
    }

    public void setNumConta(int numero) {
        if (numero > 0)
            this.numConta = numero;
        else
            System.out.println("Número inválido.");
    }

    public int getNumConta() {
        return this.numConta;
    }

    public void setSaldo(double saldo) {
        if (saldo >= 0)
            this.saldo = saldo;
        else
            System.out.println("Saldo inválido.");
    }

    public double saldo() {
        return saldo;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    public String getTitular() {
        return titular;
    }

    public void deposito(double deposito) {
        if (deposito > 0)
            this.saldo += deposito;
        else
            System.out.println("Depósito inválido.");
    }

    public void saque(double saque) {
        if (saque > 0 && saque <= this.saldo)
            this.saldo -= saque;
        else
            System.out.println("Saque inválido.");
    }
}
