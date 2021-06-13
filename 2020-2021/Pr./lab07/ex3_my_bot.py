
#1869875675:AAGyC5B3xg3ACXipXHhlAiaIUGspiZ02P0g

import random
import telebot
from telebot import types
bot = telebot.TeleBot('1869875675:AAGyC5B3xg3ACXipXHhlAiaIUGspiZ02P0g')

first = ["In the nearest future","This week","This month","This year","Tomorrow"]
second = ["you'll","your parents will","your partner will","your friend will"]
third = ["find a love","be rich","find an opportunity","get a baby ","smile"]

@bot.message_handler(content_types=['text'])
def get_text_messages(message):

    if message.text == "i want":
        bot.send_message(message.from_user.id, "Hello, i can tell your future.")

        keyboard = types.InlineKeyboardMarkup()

        key_Ram = types.InlineKeyboardButton(text='Ram', callback_data='zodiac')
        keyboard.add(key_Ram)

        key_Bull = types.InlineKeyboardButton(text='Bull', callback_data='zodiac')
        keyboard.add(key_Bull)

        key_Twins = types.InlineKeyboardButton(text='Twins', callback_data='zodiac')
        keyboard.add(key_Twins)

        key_Crab = types.InlineKeyboardButton(text='Crab', callback_data='zodiac')
        keyboard.add(key_Crab)

        key_Lion = types.InlineKeyboardButton(text='Lion', callback_data='zodiac')
        keyboard.add(key_Lion)

        key_Virgin = types.InlineKeyboardButton(text='Virgin', callback_data='zodiac')
        keyboard.add(key_Virgin)

        key_Balance = types.InlineKeyboardButton(text='Balance', callback_data='zodiac')
        keyboard.add(key_Balance)

        key_Scorpion = types.InlineKeyboardButton(text='Scorpion', callback_data='zodiac')
        keyboard.add(key_Scorpion)

        key_Archer = types.InlineKeyboardButton(text='Archer', callback_data='zodiac')
        keyboard.add(key_Archer)

        key_Goat= types.InlineKeyboardButton(text='Goat', callback_data='zodiac')
        keyboard.add(key_Goat)

        key_Aquarius = types.InlineKeyboardButton(text='Water Bearer', callback_data='zodiac')
        keyboard.add(key_Aquarius)

        key_Fish = types.InlineKeyboardButton(text='Fish', callback_data='zodiac')
        keyboard.add(key_Fish)

        bot.send_message(message.from_user.id, text='Choose your zodiac sign ', reply_markup=keyboard)
    elif message.text == "/help":
        bot.send_message(message.from_user.id, "To know your future, write 'i want' " )
    else:
        bot.send_message(message.from_user.id, "Write  /help.")

@bot.callback_query_handler(func=lambda call: True)
def callback_worker(call):
    if call.data == "zodiac":
        msg = random.choice(first) + ' ' + random.choice(second) + ' ' + random.choice(third)
        bot.send_message(call.message.chat.id, msg)
bot.polling(none_stop=True, interval=0)

