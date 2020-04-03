import random

def game_over(game_sticks):
    if game_sticks <= 0:
        return True
    else:
        return False

def num_of_sticks_allowed(player, min_stick_choice=1, max_stick_choice=3):
    player_move = ''
    while True:
        if max_stick_choice > 3:
            player_move = input('Initial number of sticks you want on the table initially ({}-{})?\n> '.format(min_stick_choice, max_stick_choice))
        else:
            player_move = input('{}: How many sticks do you take (1-3)? '.format(player))
        try:
            player_move = int(player_move)
            if min_stick_choice <= player_move <= max_stick_choice:
                break
            else:
                print('Please enter a number between {} and {}.'.format(min_stick_choice, max_stick_choice))
                continue
        except:
            print('Please enter a number between {} and {}.'.format(min_stick_choice, max_stick_choice))
            continue
    print('')
    return player_move


def initialize_ai(name):
    ret_dict = {}
    for n in list(range(1,101)):
        ret_dict[n] = {'hat': [1, 2, 3], 'beside': []}
    return ret_dict


def generate_ai_beside(ai_dict, game_sticks):
    ret = dict(ai_dict)
    ret[game_sticks]['beside'].append(random.choice(ret[game_sticks]['hat']))
    return ret[game_sticks]['beside'][0], ret

def ai_loses(ai_dict):
    temp_dict = dict(ai_dict)
    for num_sticks, stick_dict in temp_dict.items():
        if len(str(stick_dict['beside'])) > 0:
            if ai_dict[num_sticks]['beside'].count(ai_dict[num_sticks]['hat']) > 1:
                ai_dict[num_sticks]['hat'].remove(ai_dict[num_sticks]['beside'])
            ai_dict[num_sticks]['beside'] = []
    return ai_dict


def ai_wins(ai_dict):
    for num_sticks, stick_dict in ai_dict.items():
        if len(str(stick_dict['beside'])) > 0:
            stick_dict['hat'].extend(stick_dict['beside'])
            stick_dict['beside'] = []
    return ai_dict


def ai_vs_human(players, game_sticks, ai_player_1):
    count = random.randint(1,1000)           # Randomly selects human or ai for the move.
    player_move = None  # Holds the current player's move

    while True:
        print('There are {} sticks on the board.'.format(game_sticks))

        if count % 2 == 1:
            player_move, ai_player_1 = generate_ai_beside(ai_player_1, game_sticks)
            print(ai_player_1[game_sticks]['hat'])
            print('{}: {}'.format(players[count % 2], player_move))
        else:
            player_move = num_of_sticks_allowed(players[count % 2])

        game_sticks = game_sticks - player_move #Updated Sticks Total

        if game_over(game_sticks):
            print('\n{}, you lose.\n\n'.format(players[count % 2]))       
            if count % 2 == 1:
                ai_loses(ai_player_1)
            else:
                ai_wins(ai_player_1)
            break
        print('')
        count += 1
    return False

def main():
    players = []            # Holds player names and determines turn
    min_start_sticks = 7
    max_start_sticks = 150
    game_sticks = 0              

    ai_player_1 = {}

    print('Welcome to the Game of NIM!')
    players.append('Human')
    players.append('AI')
    ai_player_1 = initialize_ai('AI')

    game_sticks = num_of_sticks_allowed(players[0], min_start_sticks, max_start_sticks)
    ai_vs_human(players, game_sticks, ai_player_1)

if __name__ == '__main__':
    main()