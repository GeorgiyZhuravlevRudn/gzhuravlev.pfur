
#1869875675:AAGyC5B3xg3ACXipXHhlAiaIUGspiZ02P0g

import telebot

bot = telebot.TeleBot("1869875675:AAGyC5B3xg3ACXipXHhlAiaIUGspiZ02P0g")

@bot.message_handler(commands=['start', 'help'])
def send_welcome(message):
	bot.reply_to(message, "how is it going?")

@bot.message_handler(func=lambda message: True)
def echo_all(message):
	bot.reply_to(message, message.text)

bot.polling(none_stop=True, interval=0)

