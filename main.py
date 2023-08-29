class SistemaEntregas:
    def __init__(self):
        self.motoboys = []
        self.entregas = []
        self.numero_entrega_atual = 1

    def mostrar_menu_principal(self):
        print("PyBoy v0.2 - Sistema de Gestão de Entregas")
        print("1. Funcionários")
        print("2. Serviços")
        print("3. Sair")

    def mostrar_menu_funcionarios(self):
        print("\nMenu de Funcionários")
        print("1. Cadastrar Motoboy")
        print("2. Mostrar Funcionários")
        print("3. Enviar Mensagem ao Motoboy")
        print("4. Voltar")

    def mostrar_menu_servicos(self):
        print("\nMenu de Serviços")
        print("1. Cadastrar Entrega")
        print("2. Atribuir Motoboy à Entrega")
        print("3. Confirmar Entrega")
        print("4. Listar Entregas Pendentes")
        print("5. Voltar")

    def main(self):
        while True:
            self.mostrar_menu_principal()
            escolha = input("Escolha uma opção: ")

            if escolha == "1":
                self.menu_funcionarios()
            elif escolha == "2":
                self.menu_servicos()
            elif escolha == "3":
                break
            else:
                print("Opção inválida. Por favor, escolha novamente.")

    def menu_funcionarios(self):
        while True:
            self.mostrar_menu_funcionarios()
            escolha = input("Escolha uma opção: ")

            if escolha == "1":
                self.tela_cadastro_motoboy()
            elif escolha == "2":
                self.mostrar_todos_funcionarios()
            elif escolha == "3":
                self.tela_enviar_mensagem()
            elif escolha == "4":
                break
            else:
                print("Opção inválida. Por favor, escolha novamente.")

    def mostrar_todos_funcionarios(self):
        print("\nFuncionários Cadastrados:")
        for motoboy in self.motoboys:
            print(f"Nome: {motoboy['nome']} - Telefone: {motoboy['telefone']}")
        print()

    def tela_cadastro_motoboy(self):
        print("\nCadastro de Motoboy")
        nome = input("Nome do Motoboy: ")
        telefone = input("Telefone do Motoboy: ")
        self.motoboys.append({"nome": nome, "telefone": telefone})
        print("Motoboy cadastrado com sucesso!\n")

    def tela_enviar_mensagem(self):
        print("\nEnvio de Mensagem ao Motoboy")
        nome_motoboy = input("Nome do Motoboy: ")
        motoboy = next((m for m in self.motoboys if m["nome"] == nome_motoboy), None)

        if motoboy:
            mensagem = input("Digite a mensagem: ")
            print(f"Mensagem enviada para {nome_motoboy}: {mensagem}\n")
        else:
            print("Motoboy não encontrado!\n")

    def menu_servicos(self):
        while True:
            self.mostrar_menu_servicos()
            escolha = input("Escolha uma opção: ")

            if escolha == "1":
                self.tela_cadastro_entrega()
            elif escolha == "2":
                self.tela_atribuir_motoboy()
            elif escolha == "3":
                self.tela_confirmar_entrega()
            elif escolha == "4":
                self.tela_entregas_pendentes()
            elif escolha == "5":
                break
            else:
                print("Opção inválida. Por favor, escolha novamente.")

    def tela_cadastro_entrega(self):
        print("\nCadastro de Entrega")
        endereco = input("Endereço de Entrega: ")
        telefone_cliente = input("Telefone do Cliente: ")
        self.entregas.append({"numero": self.numero_entrega_atual, "endereco": endereco, "telefone_cliente": telefone_cliente, "motoboy": None})
        self.numero_entrega_atual += 1
        print("Entrega cadastrada com sucesso!\n")

    def tela_atribuir_motoboy(self):
        print("\nAtribuição de Motoboy à Entrega")
        numero_entrega = int(input("Número da Entrega: "))
        nome_motoboy = input("Nome do Motoboy: ")
        
        motoboy = next((m for m in self.motoboys if m["nome"] == nome_motoboy), None)
        entrega = next((e for e in self.entregas if e["numero"] == numero_entrega), None)
        
        if motoboy and entrega:
            entrega["motoboy"] = motoboy
            print("Motoboy atribuído à entrega!\n")
        else:
            print("Motoboy ou Entrega não encontrados.\n")

    def tela_confirmar_entrega(self):
        print("\nConfirmação de Entrega")
        numero_entrega = int(input("Número da Entrega: "))
        entrega = next((e for e in self.entregas if e["numero"] == numero_entrega), None)

        if entrega and entrega["motoboy"]:
            self.entregas.remove(entrega)
            print("Entrega confirmada e removida da lista de pendentes!\n")
        else:
            print("Entrega ou Motoboy não encontrados.\n")

    def tela_entregas_pendentes(self):
        print("\nEntregas Pendentes:")
        for entrega in self.entregas:
            status = "Pendente" if entrega["motoboy"] is None else f"Atribuída a {entrega['motoboy']['nome']}"
            print(f"Entrega {entrega['numero']} - {status} - Endereço: {entrega['endereco']} - Telefone do cliente: {entrega['telefone_cliente']}")
        print()

if __name__ == "__main__":
    app = SistemaEntregas()
    app.main()
