cantidad_padwans = int(input("Ingrese la cantidad de padwans: "))
contado_lado_oscuro = 0

for i in range(cantidad_padwans):
    cantidad_midicloras = int(input("Ingrese la cantidad de midicloras: "))
    
    numero = cantidad_midicloras
    residuos = []

    while numero > 0:
        residuo = numero % 5
        residuos.append(residuo)
        numero = numero // 5

    residuos.reverse()

    cantidad_digitos = residuos.count(4)

    if cantidad_digitos > 1:
        print("SI")
        contado_lado_oscuro += 1
    else:
        print("NO")

if cantidad_padwans > 0:
    porcentaje = (contado_lado_oscuro / cantidad_padwans) * 100
    print("Porcentaje:", porcentaje)
else:
    print("No hay padawans para evaluar")



