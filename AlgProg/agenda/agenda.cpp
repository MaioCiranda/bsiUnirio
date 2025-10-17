#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

const int LIMITE_PACIENTES = 50;
const int LIMITE_CARACTERES = 51;
const int IDADE_MINIMA = 13;
const int LIMITE_CONSULTAS = 100;
const int HORARIO_MINIMO = 8;
const int HORARIO_MAXIMO = 19;
const int INCREMENTO_MINUTOS = 15;

struct data
{
  int ano;
  int mes;
  int dia;
  int hora;
  int min;
  int seg;
};

struct paciente
{
  long long cpf;
  char nome[LIMITE_CARACTERES];
  int nascimento;
};

struct consulta
{
  long long cpf;
  int data_consulta;
  int hora_inicial;
  int hora_final;
};

//Funções auxiliares

bool cpf_valido(long long cpf)
{
  int primeiro_dv, segundo_dv, soma, resto, j, k;
  long long numero_cpf;
  int mult[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

  if (cpf < 11111111111L || cpf > 99999999999L || cpf % 11111111111L == 0)
    return false;

  primeiro_dv = cpf % 100 / 10,
  segundo_dv  = cpf % 10;

  numero_cpf = cpf / 100;
  soma = 0;
  for (int i = 0; i < 9; i++)
  {
    soma += (numero_cpf % 10) * mult[i];
    numero_cpf /= 10;
  }

  resto = soma % 11;

  if (resto == 0 || resto == 1)
    j = 0;
  else
    j = 11 - resto;

  if (j != primeiro_dv)
    return false;

  numero_cpf = cpf / 10;
  soma = 0;
  for (int i = 0; i < 10; i++)
  {
    soma += (numero_cpf % 10) * mult[i];
    numero_cpf /= 10;
  }

  resto = soma % 11;

  if (resto == 0 || resto == 1)
    k = 0;
  else
    k = 11 - resto;

  if (k != segundo_dv)
    return false;

  return true;
}


void data_hora_atual(int &dia, int &mes, int &ano,
int &hora, int &min, int &seg) 
{
  time_t t = time(NULL);
  struct tm lt = *localtime(&t);
  ano = lt.tm_year + 1900;
  mes = lt.tm_mon + 1;
  dia = lt.tm_mday;
  hora = lt.tm_hour;
  min = lt.tm_min;
  seg = lt.tm_sec;
}


data int_para_data (int data_int)
{
  data data_struct;
  data_struct.ano = data_int % 10000;
  data_struct.mes = (data_int % 1000000) / 10000;
  data_struct.dia = data_int / 1000000;
  return data_struct;
} 

// Confere se a data y já passou da data x
bool ja_passou (int data_y, int hora_y, int x)
{
  
  data y_convertido = int_para_data(data_y);
  y_convertido.hora = hora_y / 100;
  y_convertido.min = hora_y % 100;
  
  void data_hora_atual(int &dia, int &mes, int &ano,
  int &hora, int &min, int &seg);
  data data_atual;
  data_hora_atual(data_atual.dia, data_atual.mes, data_atual.ano, data_atual.hora,
                  data_atual.min, data_atual.seg);

  int dias = (data_atual.ano - y_convertido.ano) * 365 +
             (data_atual.mes - y_convertido.mes) * 30 +
              data_atual.dia - y_convertido.dia;
  if (dias > x * 365)
    return true;
  else if (dias < x * 365)
    return false;
  else if ((data_atual.hora - y_convertido.hora) * 60 +
           (data_atual.min - y_convertido.min) < 0)
    return false;
  return true;
}


bool data_valida(int data_int)
{
  data data_convertida = int_para_data(data_int);
  if (data_convertida.ano < 1900)
    return false;

  if (data_convertida.mes < 1 || data_convertida.mes > 12)
    return false;

  if (data_convertida.dia < 1 || data_convertida.dia > 31)
    return false;

  if ((data_convertida.mes == 4 || data_convertida.mes == 6 ||
       data_convertida.mes == 9 || data_convertida.mes == 11)
       && data_convertida.dia == 31)
    return false;

  if (data_convertida.mes == 2 && data_convertida.dia > 29)
    return false;

  if (data_convertida.ano % 4 != 0 && data_convertida.mes == 2 && data_convertida.dia == 29)
    return false;

  return true;
}


bool hora_valida(int horario_inicial, int horario_final)
{
  int hora_inicial = horario_inicial / 100;
  int min_inicial  = horario_inicial % 100;
  int hora_final = horario_final / 100;
  int min_final  = horario_final % 100;
  if (hora_inicial < HORARIO_MINIMO) 
      return false;

  if (hora_final == HORARIO_MAXIMO && min_final != 0)
      return false;

  if (min_inicial % INCREMENTO_MINUTOS != 0)
      return false;

  if (min_final % INCREMENTO_MINUTOS != 0)
      return false;

  if (hora_inicial > hora_final)
      return false;

  if (hora_final > HORARIO_MAXIMO)
      return false;

  if (hora_inicial == hora_final && min_inicial >= min_final)
      return false;
  
  if (min_inicial < 0 || min_inicial >= 60)
    return false;
  
  if (min_final < 0 || min_final >= 60)
    return false;
  
  return true;

}

// Função que retorna a posição do CPF na lista ou -1 para cpfs não cadastrados
int posicao_paciente(paciente lista[LIMITE_PACIENTES], long long cpf)
{
  for (int i = 0; i < LIMITE_PACIENTES; i++)
  {
    if (lista[i].cpf == cpf)
      return i;
  }
  return -1;
}

// Faz o mesmo que a função acima, porém com as consultas
int posicao_consulta(consulta lista[LIMITE_CONSULTAS], long long cpf)
{
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if (lista[i].cpf == cpf)
      return i;
  }
  return -1;
}


bool horario_livre(consulta lista[LIMITE_CONSULTAS], int hora_inicial,
                   int hora_final, int data_int)
{
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if ((hora_inicial >= lista[i].hora_inicial && hora_inicial < lista[i].hora_final) &&
       (hora_final > lista[i].hora_inicial && hora_final <= lista[i].hora_final) &&
       (lista[i].cpf != 0) && data_int == lista[i].data_consulta)
      return false;
  }
  return true;
}

// Transfere as consultas passadas para o histórico.
void limpar_consultas(consulta lista[LIMITE_CONSULTAS], consulta historico[LIMITE_CONSULTAS])
{
  void data_hora_atual(int &dia, int &mes, int &ano,
  int &hora, int &min, int &seg);
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if (lista[i].cpf != 0 && ja_passou(lista[i].data_consulta, lista[i].hora_final, 0) == true)
    {
      int espaco = posicao_consulta(historico, 0);
      historico[espaco] = lista[i];
      lista[i].cpf = 0;
    }
  }
}


long long cpf_valido_agendamento(consulta lista_consultas[], paciente lista_pacientes[])
{
  long long cpf = 0;
  int n;
  int posicao;
  printf("CPF: ");
  scanf(" %lld", &cpf);
  n = posicao_paciente(lista_pacientes, cpf);
  posicao = posicao_consulta(lista_consultas, cpf);
  data data_convertida = int_para_data(lista_consultas[posicao].data_consulta);

  if ( n == -1 || cpf == 0)
  {
    printf("CPF não cadastrado.\n");
    return 0;
  }
  else if (posicao != -1)
  {
    printf("O paciente já possui uma consulta agendada para dia "
    "%.2d/%.2d/%d as %.2d:%.2d.\n", data_convertida.dia, data_convertida.mes, 
    data_convertida.ano, lista_consultas[posicao].hora_inicial / 100,
    lista_consultas[posicao].hora_inicial % 100);
    return 0;
  }
  return cpf;
}


paciente* sort_paciente_cpf(paciente lista[LIMITE_PACIENTES])
{
  
  int ntrocas = 1;
  while (ntrocas != 0)
  {
    ntrocas = 0;
    for (int i = 0;  i < LIMITE_PACIENTES - 1; i++)
    {
      if (lista[i].cpf > lista[i + 1].cpf)
      {
        paciente temp = lista[i];
        lista[i] = lista[i + 1];
        lista[i + 1] = temp;
        ntrocas += 1;
      }
    }
  }

  for (int i = 0;  i < LIMITE_PACIENTES; i++)
  {
    for (int j = 0; j < LIMITE_CARACTERES; j++)
    {
      if (isalnum(lista[i].nome[j]) == 0 && isblank(lista[i].nome[j]) == 0)
        lista[i].nome[j] = '\0';
    }
  }
  return lista;
}


paciente* sort_paciente_nome(paciente lista[LIMITE_PACIENTES])
{
  
  int ntrocas = 1;
  while (ntrocas != 0)
  {
    ntrocas = 0;
    for (int i = 0;  i < LIMITE_PACIENTES - 1; i++)
    {
      if (strcmp(lista[i].nome, lista[i + 1].nome) > 0)
      {
        paciente temp = lista[i];
        lista[i] = lista[i + 1];
        lista[i + 1] = temp;
        ntrocas += 1;
      }
    }
  }
  for (int i = 0;  i < LIMITE_PACIENTES; i++)
  {
    for (int j = 0; j < LIMITE_CARACTERES; j++)
    {
      if (isalnum(lista[i].nome[j]) == 0 && isblank(lista[i].nome[j]) == 0)
        lista[i].nome[j] = '\0';
    }
  }
  return lista;
}

int diferenca(int inicial, int final)
{
  int hora_inicial = inicial / 100;
  int min_inicial  = inicial % 100;
  int hora_final = final / 100;
  int min_final  = final % 100;
  int minutagem_total = (hora_final - hora_inicial) * 60 + min_final - min_inicial;
  int diferenca = minutagem_total / 60 * 100 + minutagem_total % 60;
  return diferenca;
}

//Funções Principais

int menu_principal()
{
  int n;
  printf("\nMenu Principal\n1-Cadastro de pacientes\n2-Agenda\n3-Fim\n");
  scanf(" %d", &n);
  return n;
}

int menu_cadastro()
{
  int n;
  printf("\nMenu do Cadastro de Pacientes\n"
         "1-Cadastrar novo paciente\n"
         "2-Excluir paciente\n"
         "3-Listar pacientes (ordenado por CPF)\n"
         "4-Listar pacientes (ordenado por nome)\n"
         "5-Voltar p/ menu principal\n");
  scanf("%d", &n);
  return n;
}

int menu_agenda()
{
  int n;
  printf("\nAgenda\n"
         "1-Agendar consulta\n"
         "2-Cancelar agendamento\n"
         "3-Listar agenda\n"
         "4-Voltar p/ menu principal\n");
  scanf("%d", &n);
  return n;
}

paciente cadastro_paciente()
{
  paciente paciente_novo;
  int paciente_valido = 0;

  // CPF
  long long cpf;
  while (cpf_valido(cpf) == false)
  {
    printf("CPF: ");
    scanf("%lld", &cpf);
    if (cpf_valido(cpf) == false)
      printf("CPF inválido.\n");
  }
  paciente_novo.cpf = cpf;

  // Nome
  char nome[LIMITE_CARACTERES];
  for (;;)
  {
    printf("Nome: ");
    while (getchar() != '\n');
    fgets(nome, LIMITE_CARACTERES, stdin);
    nome[strcspn(nome, "\n")] = 0;
    if (strlen(nome) < 4)
      printf("Nome inválido\n");
    else
      break;
  }
  int i = 0;
  while (nome[i] != '\0')
  {
    paciente_novo.nome[i] = toupper(nome[i]);
    i++;
  }
  
  // Data de Nascimento
  int data_nascimento = 99999999;
  while (ja_passou(data_nascimento, 0, IDADE_MINIMA) == false
        || data_valida(data_nascimento) == false)
  {
    printf("Data de nascimento: ");
    scanf(" %d", &data_nascimento);
    if (data_valida(data_nascimento) == false)
      printf("Data inválida.\n");

    else if (ja_passou(data_nascimento, 0, IDADE_MINIMA) == false)
      printf("Apenas pacientes acima de %d anos\n", IDADE_MINIMA);
  }
  paciente_novo.nascimento = data_nascimento;
  return paciente_novo;
}

void listar_pacientes_por_cpf(paciente unsorted[LIMITE_PACIENTES] )
{
  paciente* sorted = sort_paciente_cpf(unsorted);
  printf("-------------------------------------------------------------\n"
         "CPF         Nome                              Dt.Nasc.  Idade\n"
         "-------------------------------------------------------------\n");
  for (int i = 0;  i < LIMITE_PACIENTES; i++)
  {
      if (sorted[i].cpf != 0)
      {
        int idade = IDADE_MINIMA;
        while (ja_passou(sorted[i].nascimento, 0, idade) == true)
        {
          idade++;
        }
        data convertida = int_para_data(sorted[i].nascimento); 
        printf("%lld %-33.33s %.2d/%.2d/%d  %.3i\n", sorted[i].cpf, sorted[i].nome,
        convertida.dia, convertida.mes, convertida.ano, idade - 1);
      }
  }
  printf("-------------------------------------------------------------\n");
}

void listar_pacientes_por_nome(paciente unsorted[LIMITE_PACIENTES])
{
  paciente* sorted = sort_paciente_nome(unsorted);
  printf("-------------------------------------------------------------\n"
         "CPF         Nome                              Dt.Nasc.  Idade\n"
         "-------------------------------------------------------------\n");
  for (int i = 0;  i < LIMITE_PACIENTES; i++)
  {
      if (sorted[i].cpf != 0)
      {
        int idade = IDADE_MINIMA;
        while (ja_passou(sorted[i].nascimento, 0, idade) == true)
        {
          idade++;
        }
        data convertida = int_para_data(sorted[i].nascimento); 
        printf("%lld %-33.33s %.2d/%.2d/%d  %.3i\n", sorted[i].cpf, sorted[i].nome,
        convertida.dia, convertida.mes, convertida.ano, idade - 1);
      }
  }
  printf("-------------------------------------------------------------\n");
}

consulta agendar_consulta(long long cpf, consulta lista[LIMITE_CONSULTAS])
{
  int n = posicao_consulta(lista, cpf);
  if (n != -1)
  {
    data data_convertida = int_para_data(lista[n].data_consulta);
    printf("O paciente já possui uma consulta agendada para dia"
           "%d/%d/%d as %d:%d\n", data_convertida.dia, data_convertida.mes, 
            data_convertida.ano, lista[n].hora_inicial / 100, lista[n].hora_inicial % 100);
  }
  
  consulta nova_consulta;
  nova_consulta.cpf = cpf;

  int data_int = 0;
  int hora_inicial = 0;
  int hora_final = 0;
  while (hora_valida(hora_inicial, hora_final) == false ||
         horario_livre(lista, hora_inicial, hora_final, data_int) == false ||
         data_valida(data_int) == false || ja_passou(data_int, hora_inicial, 0) == true)
  { 
    printf("Data da consulta: ");
    scanf(" %d", &data_int);
    printf("Horário inicial: ");
    scanf(" %d", &hora_inicial);
    printf("Horário final: ");
    scanf(" %d", &hora_final);
    if (data_valida(data_int) == false)
      printf("Data inválida.\n");
    if (hora_valida(hora_inicial, hora_final) == false || 
        ja_passou(data_int, hora_inicial, 0) == true)
      printf("Horário inválido.\n");
    else if (horario_livre(lista, hora_inicial, hora_final, data_int) == false)
      printf("Horário ocupado.\n");
  }
  nova_consulta.hora_inicial = hora_inicial;
  nova_consulta.hora_final   = hora_final;
  nova_consulta.data_consulta = data_int;
  return nova_consulta;

}

void listar_agenda_toda(consulta historico[], consulta agendamentos[], paciente pacientes[])
{
  printf("--------------------------------------------------------------\n"
         "   Data    H.Ini H.Fim Tempo Nome                   Dt. Nasc \n");
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if (historico[i].cpf != 0)
    {
      int n = posicao_paciente(pacientes, historico[i].cpf);
      data nascimento = int_para_data(pacientes[i].nascimento);
      data convertida = int_para_data(historico[i].data_consulta);
      int tempo = diferenca(historico[i].hora_inicial, historico[i].hora_final);
      printf("%.2d/%.2d/%.d %.2d:%.2d %.2d:%.2d %.2d:%.2d %-15.15s %.2d/%.2d/%.d",
             convertida.dia, convertida.mes, convertida.ano, historico[i].hora_inicial / 100,
             historico[i].hora_inicial % 100, historico[i].hora_final / 100,
             historico[i].hora_final % 100, tempo / 100, tempo % 100, pacientes[n].nome,
             nascimento.dia, nascimento.mes, nascimento.ano);
    } 
  }
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if (agendamentos[i].cpf != 0)
    {
      int n = posicao_paciente(pacientes, agendamentos[i].cpf);
      data nascimento = int_para_data(pacientes[i].nascimento);
      data convertida = int_para_data(agendamentos[i].data_consulta);
      int tempo = diferenca(agendamentos[i].hora_inicial, agendamentos[i].hora_final);
      printf("%.2d/%.2d/%.d %.2d:%.2d %.2d:%.2d %.2d:%.2d %-22.22s %.2d/%.2d/%.d\n",
             convertida.dia, convertida.mes, convertida.ano, agendamentos[i].hora_inicial / 100,
             agendamentos[i].hora_inicial % 100, agendamentos[i].hora_final / 100,
             historico[i].hora_final % 100, tempo / 100, tempo % 100, pacientes[n].nome,
             nascimento.dia, nascimento.mes, nascimento.ano);
    } 
  }
  printf("--------------------------------------------------------------\n");
}

void listar_agenda_periodo(consulta historico[], consulta agendamentos[], paciente pacientes[])
{
  int inicial;
  int final;
  while (data_valida(inicial) == false || data_valida(final) == false)
  {
    printf("Data inicial: ");
    scanf(" %d", &inicial);
    printf("Data final: ");
    scanf(" %d", &final);
    if (data_valida(inicial) == false || data_valida(final) == false)
      printf("Data inválida.\n");
  }
  
  printf("--------------------------------------------------------------\n"
         "   Data    H.Ini H.Fim Tempo Nome                   Dt. Nasc \n");
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if (historico[i].cpf != 0 && ja_passou(historico[i].data_consulta, 0, inicial) == false &&
        ja_passou(historico[i].data_consulta, 0, final) == true)
    {
      int n = posicao_paciente(pacientes, historico[i].cpf);
      data nascimento = int_para_data(pacientes[i].nascimento);
      data convertida = int_para_data(historico[i].data_consulta);
      int tempo = diferenca(historico[i].hora_inicial, historico[i].hora_final);
      printf("%.2d/%.2d/%.d %.2d:%.2d %.2d:%.2d %.2d:%.2d %-15.15s %.2d/%.2d/%.d",
             convertida.dia, convertida.mes, convertida.ano, historico[i].hora_inicial / 100,
             historico[i].hora_inicial % 100, historico[i].hora_final / 100,
             historico[i].hora_final % 100, tempo / 100, tempo % 100, pacientes[n].nome,
             nascimento.dia, nascimento.mes, nascimento.ano);
    } 
  }
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    if (agendamentos[i].cpf != 0 && ja_passou(agendamentos[i].data_consulta, 0, inicial) == true 
    && ja_passou(agendamentos[i].data_consulta, 0, final) == false)
    {
      int n = posicao_paciente(pacientes, agendamentos[i].cpf);
      data nascimento = int_para_data(pacientes[i].nascimento);
      data convertida = int_para_data(agendamentos[i].data_consulta);
      int tempo = diferenca(agendamentos[i].hora_inicial, agendamentos[i].hora_final);
      printf("%.2d/%.2d/%.d %.2d:%.2d %.2d:%.2d %.2d:%.2d %-22.22s %.2d/%.2d/%.d\n",
             convertida.dia, convertida.mes, convertida.ano, agendamentos[i].hora_inicial / 100,
             agendamentos[i].hora_inicial % 100, agendamentos[i].hora_final / 100,
             historico[i].hora_final % 100, tempo / 100, tempo % 100, pacientes[n].nome,
             nascimento.dia, nascimento.mes, nascimento.ano);
    } 
  }
  printf("--------------------------------------------------------------\n");
}

int main()
{
  // Listas de pacientes/consultas, populadas com 0 no índice de CPFs para indicar vazio.
  paciente lista_pacientes[LIMITE_PACIENTES];
  for (int i = 0; i < LIMITE_PACIENTES; i++)
  {
    lista_pacientes[i].cpf = 0;
  }

  consulta lista_consultas[LIMITE_CONSULTAS];
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    lista_consultas[i].cpf = 0;
  }

  consulta historico[LIMITE_CONSULTAS];
  for (int i = 0; i < LIMITE_CONSULTAS; i++)
  {
    historico[i].cpf = 0;
  }

  
  int requerimento;
  
  while (requerimento != 3)
  {
    requerimento = menu_principal();
    if (requerimento == 1)
    { 
      for (;;)
      {
        limpar_consultas(lista_consultas, historico);
        for (int i = 0;  i < LIMITE_PACIENTES; i++)
        {
          for (int j = 0; j < LIMITE_CARACTERES; j++)
          {
            if (isalnum(lista_pacientes[i].nome[j]) == 0 && 
                isblank(lista_pacientes[i].nome[j]) == 0)
              lista_pacientes[i].nome[j] = '\0';
          }
        }

        int requisito_cadastro = menu_cadastro();
        if (requisito_cadastro == 5)
          break;
        switch (requisito_cadastro)
        {
          case 1:
          {
            int espaco = posicao_paciente(lista_pacientes, 0);
            if (espaco == -1)
            {
              printf("Limite de pacientes atingido.");
              break;
            }
            paciente paciente_temp = cadastro_paciente();
            
            int existe = posicao_paciente(lista_pacientes, paciente_temp.cpf);
            if (existe != -1)
              printf("Paciente já Cadastrado.\n");
            else
            {
              lista_pacientes[espaco] = paciente_temp;
              printf("Paciente cadastrado com sucesso!\n");
            }
            break;
          } 
          
          case 2:
          {
            long long cpf_a_excluir;
            printf("CPF: ");
            scanf("%lld", &cpf_a_excluir);
            int tem = posicao_consulta(lista_consultas, cpf_a_excluir);
            int n = posicao_paciente(lista_pacientes, cpf_a_excluir);
            if (n == -1)
              printf("\nPaciente não cadastrado.");
            else if (tem != -1)
            {
              data data_convertida = int_para_data(lista_consultas[tem].data_consulta);
              printf("%s possui uma consulta agendada para dia "
                "%.2d/%.2d/%d as %.2d:%.2d e não pode ser excluído.\n",
                lista_pacientes[n].nome, data_convertida.dia, data_convertida.mes, 
                data_convertida.ano, lista_consultas[tem].hora_inicial / 100,
                lista_consultas[tem].hora_inicial % 100);
            }
            else if (posicao_consulta(historico, cpf_a_excluir) == -1)
              printf("Paciente ainda não agendou uma consulta.\n");
            else
            {
              for (int i = 0; i < LIMITE_CONSULTAS; i++)
              {
                if (historico[i].cpf == cpf_a_excluir)
                  historico[i].cpf = 0;
              }
              lista_pacientes[n].cpf = 0;
              printf("\nPaciente excluído com sucesso!\n");
            }
            break;
          }

          case 3:
            listar_pacientes_por_cpf(lista_pacientes);
            break;
          case 4:
            listar_pacientes_por_nome(lista_pacientes);
            break;
          default:
            printf("Requerimento inválido.\n");
            break;
        }
      }
    }
    if (requerimento == 2)
      for(;;)
      {
        limpar_consultas(lista_consultas, historico);
        int requisito_agenda = menu_agenda();
        if (requisito_agenda == 4)
          break;
        switch (requisito_agenda)
        {
          case 1:
          {
            int espaco = posicao_consulta(lista_consultas, 0);
            if (espaco == -1)
              printf("Limite de consultas atingido.\n");
            else
            {
              long long cpf_agendamento = cpf_valido_agendamento(lista_consultas, lista_pacientes);
              {
                if (cpf_agendamento != 0)
                {
                  consulta temp = agendar_consulta(cpf_agendamento, lista_consultas);
                  lista_consultas[espaco] = temp;
                  printf("Agendamento realizado com sucesso!\n");
                }
              }
            }

          }
            break;
          case 2:
          {
            printf("CPF: ");
            long long cpf;
            scanf("%lld", &cpf);
            int posicao_p = posicao_paciente(lista_pacientes, cpf);
            int posicao_c = posicao_consulta(lista_consultas, cpf);
            if (posicao_p == -1)
              printf("Paciente não cadastrado.\n");
            else if (posicao_c == -1)
              printf("Paciente não possui consultas futuras.\n");
            else
            {
              lista_consultas[posicao_c].cpf = 0;
              printf("Consulta desmarcada com sucesso!\n");
            }
          }
            break;
          case 3:
          {  
            char c;
            printf("Apresentar agenda T-Toda ou P-Período: ");
            scanf(" %c", &c);
            if (toupper(c) == 'T')
              listar_agenda_toda(historico, lista_consultas, lista_pacientes);
            if (toupper(c) == 'P')
              listar_agenda_periodo(historico, lista_consultas, lista_pacientes);
          }
            break;
          default:
            printf("Requerimento inválido\n");
            break;
        }
      }
    if (requerimento < 1 || requerimento > 3)
      printf("Requerimento inválido.\n");
    }
  return 0;
}
