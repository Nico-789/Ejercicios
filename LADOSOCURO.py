class Cajero:
    def __init__(self, saldo, clave):
        self.saldo = saldo
        self.clave = clave
        self.intentos = 0

    def validar_clave(self):
        while self.intentos < 3:
            clave_ingresada = input("Ingrese su clave: ")
            if clave_ingresada == self.clave:
                return True
            else:
                self.intentos += 1
                print("Clave incorrecta")
        return False

    def consultar_saldo(self):
        print("Su saldo es:", self.saldo)

    def retirar_saldo(self):
        monto = int(input("Ingrese el monto que desea retirar: "))
        if monto > self.saldo:
            print("Saldo insuficiente")
        elif monto <= 0:
            print("Monto inválido")
        else:
            self.saldo -= monto
            print("Transacción exitosa")


# 🔹 PROGRAMA PRINCIPAL
cajero = Cajero(500000, "1234")

if cajero.validar_clave():
    while True:
        print("\n1. Retirar")
        print("2. Consultar saldo")
        print("3. Salir")

        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            cajero.retirar_saldo()
        elif opcion == "2":
            cajero.consultar_saldo()
        elif opcion == "3":
            print("Gracias por usar el cajero")
            break
        else:
            print("Opción inválida")
else:
    print("Tarjeta bloqueada")
