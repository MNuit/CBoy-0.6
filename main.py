class DeliverySystem:
    def __init__(self):
        self.motoboys = []
        self.deliveries = []
        self.current_delivery_number = 1

    def show_menu(self):
        print("PyBoy - Sistema de Gestão de Entregas")
        print("1. Cadastrar Motoboy")
        print("2. Cadastrar Entrega")
        print("3. Atribuir Motoboy a Entrega")
        print("4. Confirmar Entrega")
        print("5. Listar Entregas Pendentes")
        print("6. Enviar Mensagem ao Motoboy")
        print("7. Sair")

    def run(self):
        while True:
            self.show_menu()
            choice = input("Escolha uma opção: ")

            if choice == "1":
                self.add_motoboy()
            elif choice == "2":
                self.add_delivery()
            elif choice == "3":
                self.assign_motoboy()
            elif choice == "4":
                self.confirm_delivery()
            elif choice == "5":
                self.pending_deliveries()
            elif choice == "6":
                self.send_message()
            elif choice == "7":
                break
            else:
                print("Opção inválida. Por favor, escolha novamente.")

    def add_motoboy(self):
        name = input("Nome do Motoboy: ")
        phone = input("Telefone do Motoboy: ")
        self.motoboys.append({"name": name, "phone": phone})
        print("Motoboy cadastrado com sucesso!")

    def add_delivery(self):
        address = input("Endereço de Entrega: ")
        customer_phone = input("Telefone do Cliente: ")
        self.deliveries.append({"number": self.current_delivery_number, "address": address, "customer_phone": customer_phone, "motoboy": None})
        self.current_delivery_number += 1
        print("Entrega cadastrada com sucesso!")

    def assign_motoboy(self):
        delivery_number = int(input("Número da Entrega: "))
        motoboy_name = input("Nome do Motoboy: ")
        
        motoboy = next((m for m in self.motoboys if m["name"] == motoboy_name), None)
        delivery = next((d for d in self.deliveries if d["number"] == delivery_number), None)
        
        if motoboy and delivery:
            delivery["motoboy"] = motoboy
            print("Motoboy atribuído à entrega!")

    def confirm_delivery(self):
        delivery_number = int(input("Número da Entrega: "))
        delivery = next((d for d in self.deliveries if d["number"] == delivery_number), None)

        if delivery and delivery["motoboy"]:
            self.deliveries.remove(delivery)
            print("Entrega confirmada e removida da lista de pendentes!")

    def pending_deliveries(self):
        print("Entregas Pendentes:")
        for delivery in self.deliveries:
            status = "Pendente" if delivery["motoboy"] is None else f"Atribuída a {delivery['motoboy']['name']}"
            print(f"Entrega {delivery['number']} - {status} - Endereço: {delivery['address']} - Cliente: {delivery['customer_phone']}")

    def send_message(self):
        motoboy_name = input("Nome do Motoboy: ")
        motoboy = next((m for m in self.motoboys if m["name"] == motoboy_name), None)

        if motoboy:
            message = input("Digite a mensagem: ")
            print(f"Mensagem enviada para {motoboy_name}: {message}")
        else:
            print("Motoboy não encontrado!")

if __name__ == "__main__":
    app = DeliverySystem()
    app.run()
