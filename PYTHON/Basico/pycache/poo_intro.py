class Player:
    def __init__(self, nome, arma, habilidade):
        self.__nome = nome
        self.__arma = arma
        self.__habilidade = habilidade

def get_nome(self):
    print(f"Nome:{self.__nome}")

def get_arma(self):
    print(f"Arma:{self.__arma}")

def get_habilidade(self):
    print(f"Habilidade:{self.__habilidade}")

def set_nome(self,nome):
    self.__nome = nome

bom_de_Guerra: Player = Player('Kleiton', 'Lâminas do Kaos', 'Furia de Esparta')
doom: Player = Player('Doom GUY', 'serra elétrica', 'Sem medo')

print(f"O grande {bom_de_Guerra.nome} usa suas {bom_de_Guerra.arma} junto a sua grande habilidade, {bom_de_Guerra.habilidade}")
