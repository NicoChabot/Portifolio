#include <iostream>
#include <locale>

using namespace std;

typedef struct
{
    int codigo;
    char nome[100];
    char cargo[50];
    float salario;
    struct
    {
        int ddd;
        char nro[11];
    }telefone;
    int status;
}funcionario;

int localizaCodigo(FILE *funcionarios, int codigo)
{
    int posicao=-1, achou=0;
    funcionario n;
    fseek(funcionarios, 0, SEEK_SET);
    fread(&n, sizeof(n),1, funcionarios);
    while(!feof(funcionarios) && !achou)
    {
        posicao++;
        if(n.codigo==codigo)
        {
            achou=1;
        }
        fread(&n, sizeof(n), 1, funcionarios);
    }
    if(achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}

int localizaNome (FILE *funcionarios, int codigo)
{
    int posicao=-1, demitido=0;
    funcionario n;
    fseek(funcionarios, 0, SEEK_SET);
    fread(&n, sizeof(n), 1, funcionarios);
    while(!feof(funcionarios) && !demitido)
    {
        posicao++;
        if(n.codigo==codigo)
        {
            if(n.status==1)
            {
                demitido=1;
            }
        }
        fread(&n, sizeof(n), 1, funcionarios);
    }
    if(demitido)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void cadastraFuncionario(FILE *funcionarios)
{
    funcionario n;
    int posicao, op;
    int codigo=0;
    posicao=localizaCodigo(funcionarios, codigo);
    while(posicao!=-1)
    {
        codigo++;
        posicao=localizaCodigo(funcionarios, codigo);
    }
    if(posicao==-1)
    {
        n.codigo=codigo;
        cout<<"Código: "<<n.codigo<<endl;
        cout<<"Digite o nome do funcionário: ";
        fflush(stdin);
        gets(n.nome);
        cout<<"Digite o cargo do funcionário: ";
        fflush(stdin);
        gets(n.cargo);
        cout<<"Digite o salário do funcionário: R$ ";
        fflush(stdin);
        cin>>n.salario;
        cout<<"Digite o DDD do telefone do cliente: ";
        fflush(stdin);
        cin>>n.telefone.ddd;
        cout<<"Digite o número de telefone do cliente: ";
        fflush(stdin);
        gets(n.telefone.nro);
        n.status=0;
        fseek(funcionarios, 0, SEEK_END);
        fwrite(&n, sizeof(n), 1, funcionarios);
        fflush(funcionarios);
        cout<<"Registro gravado com sucesso."<<endl<<endl;
        cout<<"1......Cadastro de novo funcionário"<<endl;
        cout<<"0......Voltar ao menu de funcionários"<<endl;
        cout<<"Digite a opção: ";
        cin>>op;
        while(op==1)
        {
            codigo++;
            posicao=localizaCodigo(funcionarios, codigo);
            while(posicao!=-1)
            {
                codigo++;
                posicao=localizaCodigo(funcionarios, codigo);
            }
            n.codigo=codigo;
            cout<<"Código: "<<n.codigo<<endl;
            cout<<"Digite o nome do funcionário: ";
            fflush(stdin);
            gets(n.nome);
            cout<<"Digite o cargo do funcionário: ";
            fflush(stdin);
            gets(n.cargo);
            cout<<"Digite o salário do funcionário: R$ ";
            fflush(stdin);
            cin>>n.salario;
            cout<<"Digite o DDD do telefone do cliente: ";
            fflush(stdin);
            cin>>n.telefone.ddd;
            cout<<"Digite o número de telefone do cliente: ";
            fflush(stdin);
            gets(n.telefone.nro);
            n.status=0;
            fseek(funcionarios, 0, SEEK_END);
            fwrite(&n, sizeof(n), 1, funcionarios);
            fflush(funcionarios);
            cout<<"Registro gravado com sucesso."<<endl<<endl;
            cout<<"1......Cadastro de novo funcionário"<<endl;
            cout<<"0......Voltar ao menu de funcionários"<<endl;
            cout<<"Digite a opção: ";
            cin>>op;
            if (op<0 || op>1)
            {
                cout<<"Opção inválida."<<endl;
                cout<<"1......Cadastro de novo funcionário"<<endl;
                cout<<"0......Voltar ao menu de funcionários"<<endl;
                cout<<"Digite a opção: ";
                cin>>op;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<"Voltando ao menu de funcionários..."<<endl;
}

void alteraFuncionario(FILE *funcionarios)
{
    int codigo, posicao;
    funcionario n;
    cout<<"Digite o código do funcionário que deseja alterar: ";
    cin>>codigo;
    posicao=localizaCodigo(funcionarios, codigo);
    while(posicao==-1)
    {
        cout<<"Código não encontrado."<<endl;
        cout<<"Digite novamente um código existente: ";
        cin>>codigo;
        posicao=localizaCodigo(funcionarios, codigo);
    }
    if(posicao!=-1)
    {
        int op=0;
        fseek(funcionarios, sizeof(n)*(posicao), SEEK_SET);
        fread(&n, sizeof(n), 1, funcionarios);
        cout<<"Código: "<<n.codigo<<endl;
        cout<<"Nome: "<<n.nome<<endl;
        cout<<"Cargo: "<<n.cargo<<endl;
        cout<<"Salário: R$ "<<n.salario<<endl;
        cout<<"Tel.: ("<<n.telefone.ddd<<") "<<n.telefone.nro<<endl;
        cout<<"1......Alterar nome"<<endl;
        cout<<"2......Alterar cargo"<<endl;
        cout<<"3......Alterar salário"<<endl;
        cout<<"4......Alterar telefone"<<endl;
        cout<<"0......Cancelar e voltar ao menu de funcionários"<<endl;
        cout<<"Digite a opção referente ao dado do funcionário que deseja alterar: ";
        fflush(stdin);
        cin>>op;
        while(op!=0)
        {
            if(op<0 || op>4)
            {
                cout<<"Opção inválida."<<endl;
                cout<<"1......Alterar nome"<<endl;
                cout<<"2......Alterar cargo"<<endl;
                cout<<"3......Alterar salário"<<endl;
                cout<<"4......Alterar telefone"<<endl;
                cout<<"0......Cancelar e voltar ao menu de funcionários"<<endl;
                cout<<"Digite a opção referente ao dado do funcionário que deseja alterar: ";
                fflush(stdin);
                cin>>op;
            }
            else
            {
                if(op==1)
                {
                    cout<<"Digite o nome atualizado do funcionário:"<<endl;
                    fflush(stdin);
                    gets(n.nome);
                    fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                    fwrite(&n, sizeof(n), 1, funcionarios);
                    fflush(funcionarios);
                    cout<<"Nome alterado com sucesso."<<endl;
                    op=0;
                }
                else
                {
                    if(op==2)
                    {
                        cout<<"Digite o novo cargo do funcionário: ";
                        fflush(stdin);
                        gets(n.cargo);
                        fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                        fwrite(&n, sizeof(n), 1, funcionarios);
                        fflush(funcionarios);
                        cout<<"Cargo atualizado com sucesso."<<endl;
                        op=0;
                    }
                    else
                    {
                        if(op==3)
                        {
                            cout<<"Digite o novo salário do funcionário: R$ ";
                            fflush(stdin);
                            cin>>n.salario;
                            fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                            fwrite(&n, sizeof(n), 1, funcionarios);
                            fflush(funcionarios);
                            cout<<"Salário atualizado com sucesso."<<endl;
                            op=0;
                        }
                        else
                        {
                            if(op==4)
                            {
                                cout<<"Digite o DDD do telefone do funcionário: ";
                                fflush(stdin);
                                cin>>n.telefone.ddd;
                                cout<<"Digite o número de telefone do funcionário: ";
                                fflush(stdin);
                                gets(n.telefone.nro);
                                fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                                fwrite(&n, sizeof(n), 1, funcionarios);
                                fflush(funcionarios);
                                cout<<"Número de telefone alterado com sucesso."<<endl;
                                op=0;
                            }
                        }
                    }
                }
            }
        }
        cout<<"Voltando ao menu de funcionários..."<<endl;
    }
}

void demiteFuncionario(FILE *funcionarios)
{
    int codigo, posicao;
    funcionario n;
    cout<<"Digite o código do funcionário que será demitido: ";
    cin>>codigo;
    posicao=localizaCodigo(funcionarios, codigo);
    while(posicao==-1)
    {
        cout<<"Código não encontrado."<<endl;
        cout<<"Digite novamente um código existente: ";
        cin>>codigo;
        posicao=localizaCodigo(funcionarios, codigo);
    }
    if(posicao!=-1)
    {
        int op=0;
        fseek(funcionarios, sizeof(n)*(posicao), SEEK_SET);
        fread(&n, sizeof(n), 1, funcionarios);
        do
        {
            if(n.status==1)
            {
                cout<<"O funcionário "<<n.nome<<" já está demitido."<<endl;
            }
            else
            {
                fseek(funcionarios, sizeof(n)*(posicao), SEEK_SET);
                fread(&n, sizeof(n), 1, funcionarios);
                cout<<"Código: "<<n.codigo<<endl;
                cout<<"Nome: "<<n.nome<<endl;
                cout<<"Cargo: "<<n.cargo<<endl;
                cout<<"Salário: "<<n.salario<<endl;
                cout<<"Tel.: ("<<n.telefone.ddd<<") "<<n.telefone.nro<<endl;
                cout<<"1-CONFIRMAR; 2-CANCELAR"<<endl;
                cout<<"Tem certeza que deseja demitir o funcionário? ";
                cin>>op;
                while(op<1 || op>2)
                {
                    cout<<"Opção inválida."<<endl;
                    cout<<"1-CONFIRMAR; 2-CANCELAR"<<endl;
                    cout<<"Tem certeza que deseja demitir o funcionário? ";
                    cin>>op;
                }
                if(op==1)
                {
                    cout<<"Demitindo funcionário..."<<endl;
                    n.status=1;
                    fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                    fwrite(&n, sizeof(n), 1, funcionarios);
                    fflush(funcionarios);
                    cout<<"Registro gravado com sucesso."<<endl;
                    op=0;
                }
                else
                {
                    if((op<0) || op>2)
                    {
                        cout<<"Opção inválida."<<endl;
                        cout<<"1-CONFIRMAR; 2-CANCELAR"<<endl;
                        cout<<"Tem certeza que deseja demitir o funcionário? ";
                        cin>>op;
                    }
                    else
                        break;
                }
            }
        }
        while(op!=0);
    }
    cout<<"Voltando ao menu de funcionários..."<<endl;
}

void imprimeFuncionarios(FILE *funcionarios)
{
    funcionario n;
    fseek(funcionarios, 0, SEEK_SET);
    fread(&n, sizeof(n), 1, funcionarios);
    while(!feof(funcionarios))
    {
        if(n.status==0)
        {
            cout<<"Código: "<<n.codigo<<endl;
            cout<<"Nome: "<<n.nome<<endl;
            cout<<"Cargo: "<<n.cargo<<endl;
            cout<<"Salário: R$ "<<n.salario<<endl;
            cout<<"Tel.: ("<<n.telefone.ddd<<") "<<n.telefone.nro<<endl;
            fread(&n, sizeof(n), 1, funcionarios);
        }
        else
        {
            fread(&n, sizeof(n), 1, funcionarios);
        }
    }
    cout<<"Voltando ao menu de funcionarios..."<<endl;
}

int funcionarios()
{
    cout<<fixed;
    cout.precision(2);
    setlocale(LC_ALL, "portuguese");
    FILE *funcionarios;
    int op;
    if((funcionarios=fopen("funcionarios.dat", "r+b"))==NULL)
    {
        cout<<"Arquivo inexistente."<<endl;
        cout<<"Criando arquivo..."<<endl;
        if((funcionarios=fopen("funcionarios.dat", "w+b"))==NULL)
        {
            cout<<"Erro na criação do arquivo!!"<<endl;
            exit(1);
        }
    }
    do
    {
        cout<<"MENU DE OPÇÕES: FUNCIONÁRIOS"<<endl;
        cout<<"Cadastrar funcionário:......................1"<<endl;
        cout<<"Alterar funcionário:........................2"<<endl;
        cout<<"Demitir funcionário:........................3"<<endl;
        cout<<"Imprimir relação de funcionários ativos:....4"<<endl;
        cout<<"Voltar ao menu principal:...................0"<<endl;
        cout<<"Digite a opção: ";
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"\nCADASTRO DE FUNCIONÁRIO:"<<endl;
                cadastraFuncionario(funcionarios);
                break;
            case 2:
                cout<<"\nALTERAÇÃO DE FUNCIONÁRIO:"<<endl;
                alteraFuncionario(funcionarios);
                break;
            case 3:
                cout<<"DEMISSÃO DE FUNCIONÁRIO:"<<endl;
                demiteFuncionario(funcionarios);
                break;
            case 4:
                cout<<"\nRELAÇÃO DE FUNCIONÁRIOS ATIVOS:"<<endl;
                imprimeFuncionarios(funcionarios);
                break;
            default:
                break;
        }
        if(op<0 || op>4)
        {
            cout<<"Opção inválida."<<endl;
            cout<<"Digite outra opção válida: ";
            cin>>op;
        }
    }
    while(op!=0);
    fclose(funcionarios);
    cout<<"\nVoltando ao menu principal..."<<endl;
    return 0;
}
//
//  funcionarios.cpp
//
//  Created by Frederico Rodrigues on 14/12/20.
//

#include <iostream>
#include <locale>

using namespace std;

typedef struct
{
    int codigo;
    char nome[100];
    char cargo[50];
    float salario;
    struct
    {
        int ddd;
        char nro[11];
    }telefone;
    int status;
}funcionario;

int localizaCodigo(FILE *funcionarios, int codigo)
{
    int posicao=-1, achou=0;
    funcionario n;
    fseek(funcionarios, 0, SEEK_SET);
    fread(&n, sizeof(n),1, funcionarios);
    while(!feof(funcionarios) && !achou)
    {
        posicao++;
        if(n.codigo==codigo)
        {
            achou=1;
        }
        fread(&n, sizeof(n), 1, funcionarios);
    }
    if(achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}

int localizaNome (FILE *funcionarios, int codigo)
{
    int posicao=-1, demitido=0;
    funcionario n;
    fseek(funcionarios, 0, SEEK_SET);
    fread(&n, sizeof(n), 1, funcionarios);
    while(!feof(funcionarios) && !demitido)
    {
        posicao++;
        if(n.codigo==codigo)
        {
            if(n.status==1)
            {
                demitido=1;
            }
        }
        fread(&n, sizeof(n), 1, funcionarios);
    }
    if(demitido)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void cadastraFuncionario(FILE *funcionarios)
{
    funcionario n;
    int posicao, op;
    int codigo=0;
    posicao=localizaCodigo(funcionarios, codigo);
    while(posicao!=-1)
    {
        codigo++;
        posicao=localizaCodigo(funcionarios, codigo);
    }
    if(posicao==-1)
    {
        n.codigo=codigo;
        cout<<"Código: "<<n.codigo<<endl;
        cout<<"Digite o nome do funcionário: ";
        fflush(stdin);
        gets(n.nome);
        cout<<"Digite o cargo do funcionário: ";
        fflush(stdin);
        gets(n.cargo);
        cout<<"Digite o salário do funcionário: R$ ";
        fflush(stdin);
        cin>>n.salario;
        cout<<"Digite o DDD do telefone do cliente: ";
        fflush(stdin);
        cin>>n.telefone.ddd;
        cout<<"Digite o número de telefone do cliente: ";
        fflush(stdin);
        gets(n.telefone.nro);
        n.status=0;
        fseek(funcionarios, 0, SEEK_END);
        fwrite(&n, sizeof(n), 1, funcionarios);
        fflush(funcionarios);
        cout<<"Registro gravado com sucesso."<<endl<<endl;
        cout<<"1......Cadastro de novo funcionário"<<endl;
        cout<<"0......Voltar ao menu de funcionários"<<endl;
        cout<<"Digite a opção: ";
        cin>>op;
        while(op==1)
        {
            codigo++;
            posicao=localizaCodigo(funcionarios, codigo);
            while(posicao!=-1)
            {
                codigo++;
                posicao=localizaCodigo(funcionarios, codigo);
            }
            n.codigo=codigo;
            cout<<"Código: "<<n.codigo<<endl;
            cout<<"Digite o nome do funcionário: ";
            fflush(stdin);
            gets(n.nome);
            cout<<"Digite o cargo do funcionário: ";
            fflush(stdin);
            gets(n.cargo);
            cout<<"Digite o salário do funcionário: R$ ";
            fflush(stdin);
            cin>>n.salario;
            cout<<"Digite o DDD do telefone do cliente: ";
            fflush(stdin);
            cin>>n.telefone.ddd;
            cout<<"Digite o número de telefone do cliente: ";
            fflush(stdin);
            gets(n.telefone.nro);
            n.status=0;
            fseek(funcionarios, 0, SEEK_END);
            fwrite(&n, sizeof(n), 1, funcionarios);
            fflush(funcionarios);
            cout<<"Registro gravado com sucesso."<<endl<<endl;
            cout<<"1......Cadastro de novo funcionário"<<endl;
            cout<<"0......Voltar ao menu de funcionários"<<endl;
            cout<<"Digite a opção: ";
            cin>>op;
            if (op<0 || op>1)
            {
                cout<<"Opção inválida."<<endl;
                cout<<"1......Cadastro de novo funcionário"<<endl;
                cout<<"0......Voltar ao menu de funcionários"<<endl;
                cout<<"Digite a opção: ";
                cin>>op;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<"Voltando ao menu de funcionários..."<<endl;
}

void alteraFuncionario(FILE *funcionarios)
{
    int codigo, posicao;
    funcionario n;
    cout<<"Digite o código do funcionário que deseja alterar: ";
    cin>>codigo;
    posicao=localizaCodigo(funcionarios, codigo);
    while(posicao==-1)
    {
        cout<<"Código não encontrado."<<endl;
        cout<<"Digite novamente um código existente: ";
        cin>>codigo;
        posicao=localizaCodigo(funcionarios, codigo);
    }
    if(posicao!=-1)
    {
        int op=0;
        fseek(funcionarios, sizeof(n)*(posicao), SEEK_SET);
        fread(&n, sizeof(n), 1, funcionarios);
        cout<<"Código: "<<n.codigo<<endl;
        cout<<"Nome: "<<n.nome<<endl;
        cout<<"Cargo: "<<n.cargo<<endl;
        cout<<"Salário: R$ "<<n.salario<<endl;
        cout<<"Tel.: ("<<n.telefone.ddd<<") "<<n.telefone.nro<<endl;
        cout<<"1......Alterar nome"<<endl;
        cout<<"2......Alterar cargo"<<endl;
        cout<<"3......Alterar salário"<<endl;
        cout<<"4......Alterar telefone"<<endl;
        cout<<"0......Cancelar e voltar ao menu de funcionários"<<endl;
        cout<<"Digite a opção referente ao dado do funcionário que deseja alterar: ";
        fflush(stdin);
        cin>>op;
        while(op!=0)
        {
            if(op<0 || op>4)
            {
                cout<<"Opção inválida."<<endl;
                cout<<"1......Alterar nome"<<endl;
                cout<<"2......Alterar cargo"<<endl;
                cout<<"3......Alterar salário"<<endl;
                cout<<"4......Alterar telefone"<<endl;
                cout<<"0......Cancelar e voltar ao menu de funcionários"<<endl;
                cout<<"Digite a opção referente ao dado do funcionário que deseja alterar: ";
                fflush(stdin);
                cin>>op;
            }
            else
            {
                if(op==1)
                {
                    cout<<"Digite o nome atualizado do funcionário:"<<endl;
                    fflush(stdin);
                    gets(n.nome);
                    fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                    fwrite(&n, sizeof(n), 1, funcionarios);
                    fflush(funcionarios);
                    cout<<"Nome alterado com sucesso."<<endl;
                    op=0;
                }
                else
                {
                    if(op==2)
                    {
                        cout<<"Digite o novo cargo do funcionário: ";
                        fflush(stdin);
                        gets(n.cargo);
                        fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                        fwrite(&n, sizeof(n), 1, funcionarios);
                        fflush(funcionarios);
                        cout<<"Cargo atualizado com sucesso."<<endl;
                        op=0;
                    }
                    else
                    {
                        if(op==3)
                        {
                            cout<<"Digite o novo salário do funcionário: R$ ";
                            fflush(stdin);
                            cin>>n.salario;
                            fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                            fwrite(&n, sizeof(n), 1, funcionarios);
                            fflush(funcionarios);
                            cout<<"Salário atualizado com sucesso."<<endl;
                            op=0;
                        }
                        else
                        {
                            if(op==4)
                            {
                                cout<<"Digite o DDD do telefone do funcionário: ";
                                fflush(stdin);
                                cin>>n.telefone.ddd;
                                cout<<"Digite o número de telefone do funcionário: ";
                                fflush(stdin);
                                gets(n.telefone.nro);
                                fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                                fwrite(&n, sizeof(n), 1, funcionarios);
                                fflush(funcionarios);
                                cout<<"Número de telefone alterado com sucesso."<<endl;
                                op=0;
                            }
                        }
                    }
                }
            }
        }
        cout<<"Voltando ao menu de funcionários..."<<endl;
    }
}

void demiteFuncionario(FILE *funcionarios)
{
    int codigo, posicao;
    funcionario n;
    cout<<"Digite o código do funcionário que será demitido: ";
    cin>>codigo;
    posicao=localizaCodigo(funcionarios, codigo);
    while(posicao==-1)
    {
        cout<<"Código não encontrado."<<endl;
        cout<<"Digite novamente um código existente: ";
        cin>>codigo;
        posicao=localizaCodigo(funcionarios, codigo);
    }
    if(posicao!=-1)
    {
        int op=0;
        fseek(funcionarios, sizeof(n)*(posicao), SEEK_SET);
        fread(&n, sizeof(n), 1, funcionarios);
        do
        {
            if(n.status==1)
            {
                cout<<"O funcionário "<<n.nome<<" já está demitido."<<endl;
            }
            else
            {
                fseek(funcionarios, sizeof(n)*(posicao), SEEK_SET);
                fread(&n, sizeof(n), 1, funcionarios);
                cout<<"Código: "<<n.codigo<<endl;
                cout<<"Nome: "<<n.nome<<endl;
                cout<<"Cargo: "<<n.cargo<<endl;
                cout<<"Salário: "<<n.salario<<endl;
                cout<<"Tel.: ("<<n.telefone.ddd<<") "<<n.telefone.nro<<endl;
                cout<<"1-CONFIRMAR; 2-CANCELAR"<<endl;
                cout<<"Tem certeza que deseja demitir o funcionário? ";
                cin>>op;
                while(op<1 || op>2)
                {
                    cout<<"Opção inválida."<<endl;
                    cout<<"1-CONFIRMAR; 2-CANCELAR"<<endl;
                    cout<<"Tem certeza que deseja demitir o funcionário? ";
                    cin>>op;
                }
                if(op==1)
                {
                    cout<<"Demitindo funcionário..."<<endl;
                    n.status=1;
                    fseek(funcionarios, sizeof(n)*(posicao),SEEK_SET);
                    fwrite(&n, sizeof(n), 1, funcionarios);
                    fflush(funcionarios);
                    cout<<"Registro gravado com sucesso."<<endl;
                    op=0;
                }
                else
                {
                    if((op<0) || op>2)
                    {
                        cout<<"Opção inválida."<<endl;
                        cout<<"1-CONFIRMAR; 2-CANCELAR"<<endl;
                        cout<<"Tem certeza que deseja demitir o funcionário? ";
                        cin>>op;
                    }
                    else
                        break;
                }
            }
        }
        while(op!=0);
    }
    cout<<"Voltando ao menu de funcionários..."<<endl;
}

void imprimeFuncionarios(FILE *funcionarios)
{
    funcionario n;
    fseek(funcionarios, 0, SEEK_SET);
    fread(&n, sizeof(n), 1, funcionarios);
    while(!feof(funcionarios))
    {
        if(n.status==0)
        {
            cout<<"Código: "<<n.codigo<<endl;
            cout<<"Nome: "<<n.nome<<endl;
            cout<<"Cargo: "<<n.cargo<<endl;
            cout<<"Salário: R$ "<<n.salario<<endl;
            cout<<"Tel.: ("<<n.telefone.ddd<<") "<<n.telefone.nro<<endl;
            fread(&n, sizeof(n), 1, funcionarios);
        }
        else
        {
            fread(&n, sizeof(n), 1, funcionarios);
        }
    }
    cout<<"Voltando ao menu de funcionarios..."<<endl;
}

int funcionarios()
{
    cout<<fixed;
    cout.precision(2);
    setlocale(LC_ALL, "portuguese");
    FILE *funcionarios;
    int op;
    if((funcionarios=fopen("funcionarios.dat", "r+b"))==NULL)
    {
        cout<<"Arquivo inexistente."<<endl;
        cout<<"Criando arquivo..."<<endl;
        if((funcionarios=fopen("funcionarios.dat", "w+b"))==NULL)
        {
            cout<<"Erro na criação do arquivo!!"<<endl;
            exit(1);
        }
    }
    do
    {
        cout<<"MENU DE OPÇÕES: FUNCIONÁRIOS"<<endl;
        cout<<"Cadastrar funcionário:......................1"<<endl;
        cout<<"Alterar funcionário:........................2"<<endl;
        cout<<"Demitir funcionário:........................3"<<endl;
        cout<<"Imprimir relação de funcionários ativos:....4"<<endl;
        cout<<"Voltar ao menu principal:...................0"<<endl;
        cout<<"Digite a opção: ";
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"\nCADASTRO DE FUNCIONÁRIO:"<<endl;
                cadastraFuncionario(funcionarios);
                break;
            case 2:
                cout<<"\nALTERAÇÃO DE FUNCIONÁRIO:"<<endl;
                alteraFuncionario(funcionarios);
                break;
            case 3:
                cout<<"DEMISSÃO DE FUNCIONÁRIO:"<<endl;
                demiteFuncionario(funcionarios);
                break;
            case 4:
                cout<<"\nRELAÇÃO DE FUNCIONÁRIOS ATIVOS:"<<endl;
                imprimeFuncionarios(funcionarios);
                break;
            default:
                break;
        }
        if(op<0 || op>4)
        {
            cout<<"Opção inválida."<<endl;
            cout<<"Digite outra opção válida: ";
            cin>>op;
        }
    }
    while(op!=0);
    fclose(funcionarios);
    cout<<"\nVoltando ao menu principal..."<<endl;
    return 0;
}
