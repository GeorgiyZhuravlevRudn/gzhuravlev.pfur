
#1869875675:AAGyC5B3xg3ACXipXHhlAiaIUGspiZ02P0g

import random
import telebot
from telebot import types
bot = telebot.TeleBot("1869875675:AAGyC5B3xg3ACXipXHhlAiaIUGspiZ02P0g")
question=["Are you ok?","Don't you want to find a new job?","Can a frog eat a dog?","Do you love your country?" ]
@bot.message_handler(content_types=['text'])
def get_message(message):
	if message.text == "start":

		keyboard = types.InlineKeyboardMarkup()

		key_yes=types.InlineKeyboardButton(text='Yes', callback_data='answer')
		keyboard.add(key_yes)

		key_no = types.InlineKeyboardButton(text='No', callback_data='answer')
		keyboard.add(key_no)

		key_want = types.InlineKeyboardButton(text='I want', callback_data='answer')
		keyboard.add(key_want)

		key_DONTwant = types.InlineKeyboardButton(text="I don't want", callback_data='answer')
		keyboard.add(key_DONTwant)

		bot.send_message(message.from_user.id, text='Answer, please ', reply_markup=keyboard)
	elif message.text == "/help":
		bot.send_message(message.from_user.id, "To answer questions, write 'start' ")
	else:
		bot.send_message(message.from_user.id, "Write  /help.")

@bot.callback_query_handler(func=lambda call: True)
def callback_worker(call):
    if call.data == "answer":
        msg = random.choice(question)
        bot.send_message(call.message.chat.id, msg)
bot.polling(none_stop=True, interval=0)
