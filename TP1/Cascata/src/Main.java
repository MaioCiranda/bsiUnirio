public class Main {
    public static void main(String[] args) {
        MembroDaComunidade caio = new MembroDaComunidade();
        caio.cpf = "15535414727";
        caio.nome = "Caio";
        caio.email = "caio_mmf@hotmail.com";
        System.out.println(caio);

        Graduado farinha = new Graduado();
        farinha.cpf = "15535414727";
        farinha.nome = "Farinha";
        farinha.email = "farinha@farinhamail.com";
        farinha.curso = "História";
        farinha.dataGraduacao = "13/04/2025";
        farinha.matricula = "20181190015";
        System.out.println(farinha);

        Aluno maio = new Aluno();
        maio.cpf = "15535414727";
        maio.nome = "Maio";
        maio.email = "maiociranda@gmail.com";
        maio.curso = "Bacharelado em sistemas de informação";
        maio.cr = 8.4F;
        maio.matricula = "20242210012";
        System.out.println(maio);

        Empregado w = new Empregado();
        w.cpf = "15535414727";
        w.nome = "W";
        w.email = "w@gmail.com";
        w.horasTrabalho = 8;
        w.anoDeContratacao = 2020;
        w.salario = 2200;
        System.out.println(w);

        Funcionarios eli = new Funcionarios();
        eli.cpf = "15535414727";
        eli.nome = "W";
        eli.email = "w@gmail.com";
        eli.horasTrabalho = 8;
        eli.anoDeContratacao = 2020;
        eli.salario = 2200;
        eli.setor = "RU";
        eli.noturno = true;
        eli.funcao = "Caixa";
        System.out.println(eli);

        CorpoDocente amancio = new CorpoDocente();
        amancio.cpf = "15535414727";
        amancio.nome = "Amâncio";
        amancio.email = "amancio@gmail.com";
        amancio.horasTrabalho = 8;
        amancio.anoDeContratacao = 2000;
        amancio.salario = 23000;
        amancio.anosExperiencia = 25;
        amancio.departamento = "Matemática";
        amancio.possuiDoutorado = true;
        System.out.println(amancio);

        Professor laura = new Professor();
        laura.cpf = "15535414727";
        laura.nome = "Laura";
        laura.email = "laura@gmail.com";
        laura.horasTrabalho = 8;
        laura.anoDeContratacao = 2022;
        laura.salario = 20000;
        laura.anosExperiencia = 3;
        laura.departamento = "Informática Aplicada";
        laura.possuiDoutorado = true;
        laura.disciplinaPrincipal = "Técnicas de Programação 1";
        laura.orientador = true;
        laura.qtdTurmas = 1;
        System.out.println(laura);

        Administrador jefferson = new Administrador();
        jefferson.cpf = "15535414727";
        jefferson.nome = "Jefferson";
        jefferson.email = "jefferson@gmail.com";
        jefferson.horasTrabalho = 8;
        jefferson.anoDeContratacao = 2023;
        jefferson.salario = 30000;
        jefferson.anosExperiencia = 2;
        jefferson.departamento = "Informática Aplicada";
        jefferson.possuiDoutorado = true;
        jefferson.cargo = "Coordenador do BSI";
        jefferson.nivelAcesso = 3;
        jefferson.orcamentoAnual = 100000;
        System.out.println(jefferson);
    }
}