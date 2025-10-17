public class Tweet {
    private String paragrafo;
    static final int MAX = 144;
    private char[] vetorParagrafo;

    public Tweet(String tweet) {
        if (tweet.length() < MAX) {
            this.paragrafo = tweet;
            vetorParagrafo = tweet.toCharArray();
        }
        else
            System.out.println("Tweet ultrapassa o limite de caracteres.");

    }

    public String getParagrafo() {
        return this.paragrafo;
    }

    public int qtdCaracteres() {
        return this.paragrafo.length();
    }

    public int qtdPalavras() {
        if (this.paragrafo.isEmpty())
            return 0;
        int palavras = 1;
        for (int i = 0; i < this.vetorParagrafo.length; i++) {
            if (Character.isWhitespace(vetorParagrafo[i]))
                palavras++;
        }
        return palavras;
    }

    public int qtdFrases() {
        if (this.paragrafo.isEmpty())
            return 0;
        int frases = 0;
        for (int i = 0; i < vetorParagrafo.length; i++) {
            if (vetorParagrafo[i] == '!' || vetorParagrafo[i] == '?' ||
                (vetorParagrafo[i] == '.' && vetorParagrafo[i - 1] != '.'))
                frases++;
        }
        if (Character.isAlphabetic(vetorParagrafo[vetorParagrafo.length - 1]))
            frases++;
        return frases;
    }

    public int qtdInstancias(String palavra) {
        int instancias = this.paragrafo.split("(?i)" + palavra, -1).length - 1;
        return instancias;
    }
    public static String paragrafoAleatorio() {
        int tamanhoParagrafo = (int) (Math.random() * MAX);
        char[] vetorAleatorio = new char[tamanhoParagrafo];
        for (int i = 0; i < tamanhoParagrafo; i++) {
            vetorAleatorio[i] = (char) (Math.random() * 96 + 32);
        }

        return new String(vetorAleatorio);
    }
}

