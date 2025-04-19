import os
import time
import random

class PersonagemGame:
    def __init__(self, nome, nivel, vida, estamina, mana, forca, agilidade):
        self.nome = nome
        self.nivel = nivel
        self.vida = vida
        self.estamina = estamina
        self.mana = mana
        self.forca = forca
        self.agilidade = agilidade
        self.inventario = []

    def atacar(self, alvo):
        print(f"\n{self.nome} ataca {alvo} causando {self.forca} de dano!")

    def exibir_status(self):
        print("\n=== STATUS DO PERSONAGEM ===")
        print(f"Nome: {self.nome}")
        print(f"Nível: {self.nivel}")
        print(f"Vida: {self.vida}")
        print(f"Estamina: {self.estamina}")
        print(f"Mana: {self.mana}")
        print(f"Força: {self.forca}")
        print(f"Agilidade: {self.agilidade}")
        print(f"Inventário: {', '.join(self.inventario) if self.inventario else 'Vazio'}")
        print("-" * 30)

    def adicionar_item(self, item):
        self.inventario.append(item)


personagens = []

def limpar_tela():
    os.system('cls' if os.name == 'nt' else 'clear')

def criar_personagem():
    limpar_tela()
    print("🛠️  Criação de Personagem 🛠️\n")
    nome = input("Digite o nome do personagem: ")
    nivel = int(input("Digite o nível do personagem: "))
    vida = int(input("Digite a vida do personagem: "))
    estamina = int(input("Digite a estamina do personagem: "))
    mana = int(input("Digite a mana do personagem: "))
    forca = int(input("Digite a força do personagem: "))
    agilidade = int(input("Digite a agilidade do personagem: "))
    personagem = PersonagemGame(nome, nivel, vida, estamina, mana, forca, agilidade)

    while True:
        item = input("Adicione um item ao inventário (ENTER para parar): ")
        if item == "":
            break
        personagem.adicionar_item(item)

    personagens.append(personagem)
    print(f"\n✨ Personagem '{nome}' criado com sucesso!")
    time.sleep(2)
    limpar_tela()


def batalha(personagem):
    limpar_tela()
    inimigo = {
        "nome": "Goblin Sombrio",
        "vida": 30,
        "dificuldade": 12,
        "dano": 8
    }

    print(f"⚔️  Um {inimigo['nome']} apareceu!")
    time.sleep(1)

    while personagem.vida > 0 and inimigo["vida"] > 0:
        print("\n--- SUA VEZ ---")
        print("1 - Atacar")
        print("2 - Usar item")
        print("3 - Fugir")
        acao = input("Escolha sua ação: ")

        if acao == "1":
            rolagem = random.randint(1, 20)
            bonus = personagem.forca // 2
            total = rolagem + bonus
            print(f"\n🎲 Você rolou {rolagem} + bônus de força ({bonus}) = {total}")

            if total >= inimigo["dificuldade"]:
                dano = random.randint(5, 12) + personagem.nivel
                inimigo["vida"] -= dano
                print(f"✅ Ataque bem-sucedido! Você causou {dano} de dano.")
            else:
                print("❌ Você errou o ataque!")

        elif acao == "2":
            if not personagem.inventario:
                print("⚠️ Inventário vazio!")
            else:
                print("\n🎒 Inventário:")
                for i, item in enumerate(personagem.inventario):
                    print(f"{i + 1} - {item}")
                try:
                    escolha_item = int(input("Escolha o item para usar (número): ")) - 1
                    item = personagem.inventario.pop(escolha_item)
                    if "poção" in item.lower():
                        cura = random.randint(10, 20)
                        personagem.vida += cura
                        print(f"🧪 Você usou {item} e recuperou {cura} de vida!")
                    else:
                        print(f"🔹 Você usou {item}, mas nada aconteceu...")
                except:
                    print("❌ Escolha inválida.")
        elif acao == "3":
            fuga = random.randint(1, 20) + personagem.agilidade // 2
            if fuga >= 15:
                print("🏃‍♂️ Você conseguiu fugir com sucesso!")
                return
            else:
                print("🚫 Você falhou em fugir!")

        else:
            print("Opção inválida.")
            continue

        time.sleep(2)

        # Turno do inimigo
        if inimigo["vida"] > 0:
            print("\n--- TURNO DO INIMIGO ---")
            ataque_inimigo = random.randint(1, 20)
            defesa = 10 + personagem.agilidade // 2
            print(f"O inimigo rolou {ataque_inimigo} contra sua defesa {defesa}")

            if ataque_inimigo >= defesa:
                personagem.vida -= inimigo["dano"]
                print(f"💥 O inimigo te acertou! Você perdeu {inimigo['dano']} de vida.")
            else:
                print("🛡️ Você esquivou do ataque!")

        time.sleep(2)
        limpar_tela()
        personagem.exibir_status()

    if personagem.vida <= 0:
        print("\n💀 Você foi derrotado...")
    else:
        print(f"\n🏆 Você derrotou o {inimigo['nome']} e sobreviveu à batalha!")


def iniciar_jornada():
    if not personagens:
        print("⚠️  Crie um personagem antes de iniciar a jornada.")
        time.sleep(2)
        return

    limpar_tela()
    print("🌟 Escolha seu personagem para iniciar a jornada:\n")
    for i, p in enumerate(personagens):
        print(f"{i + 1} - {p.nome}")
    escolha = int(input("\nDigite o número do personagem escolhido: ")) - 1
    personagem = personagens[escolha]

    limpar_tela()
    personagem.exibir_status()
    input("\nPressione ENTER para começar a jornada...")
    limpar_tela()

    print("🌲 Você acorda em uma floresta misteriosa, a névoa é densa e o frio toca sua pele...")
    time.sleep(2)
    print("\nDois caminhos se revelam diante de você:")
    print("1 - Trilha de pedras reluzentes")
    print("2 - Bosque escuro e silencioso")
    escolha = input("\nQual caminho deseja seguir? (1/2): ")
    limpar_tela()

    if escolha == "1":
        print("🏡 Você encontra uma cabana com uma luz bruxuleante...")
        time.sleep(2)
        print("Um velho mago aparece e diz:")
        print("- Ah, viajante... pegue isso. Vai ajudar na sua jornada.")
        personagem.adicionar_item("📜 Mapa Mágico")
    else:
        print("👾 Criaturas sombrias surgem do bosque e te cercam!")
        time.sleep(2)
        batalha(personagem)
        personagem.adicionar_item("🧪 Poção Misteriosa")

    time.sleep(2)
    input("\nPressione ENTER para continuar...")
    limpar_tela()

    print("🚩 Após a luta, você chega a uma encruzilhada com uma placa:")
    print("1 - Cidade de Eldoria")
    print("2 - Montanhas Sombrias")
    destino = input("\nPara onde deseja ir? (1/2): ")
    limpar_tela()

    if destino == "1":
        print("🏙️ Você chega à cidade movimentada de Eldoria...")
        print("Um ferreiro se aproxima:")
        print("- Se tiver algo raro, posso forjar uma arma lendária!")
    else:
        print("⛰️ Você escala as Montanhas Sombrias...")
        print("Na caverna, uma voz misteriosa ecoa:")
        print("- Só os corajosos resistem aqui...")

    time.sleep(2)
    print("\n🌟 Sua jornada está apenas começando...")
    personagem.exibir_status()
    input("\nPressione ENTER para retornar ao menu...")
    limpar_tela()


def menu():
    while True:
        print("🎮 Bem-vindo ao RPG de Terminal 🎮")
        print("-" * 35)
        print("1 - Criar Personagem")
        print("2 - Iniciar Jornada")
        print("3 - Sair")
        print("-" * 35)
        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            criar_personagem()
        elif opcao == "2":
            iniciar_jornada()
        elif opcao == "3":
            print("\n👋 Até logo, aventureiro!")
            time.sleep(1)
            break
        else:
            print("❌ Opção inválida.")
            time.sleep(1)
            limpar_tela()


# Inicia o menu principal
limpar_tela()
menu()
