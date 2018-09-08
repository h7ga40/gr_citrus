lcd = LCD.new()
remocon = Remocon.new()

lcd.drawString(0, 0, "赤外線リモコン受信", 1, 0)

i = 0
t = 0
while t < 10000 do
	msg = remocon.recv()
	if msg
		lcd.fillRect(0, 12, lcd.width, lcd.height - 12, 0)

		i += 1
		lcd.drawString(0, 12, "#{i.to_s} #{msg[:type]}", 1, 0)

		case msg[:type].to_s
		when "NEC"
			lcd.drawString(0, 24, "code: #{msg[:code].to_s(16)}", 1, 0)
			lcd.drawString(0, 36, "data: #{msg[:data].to_s(16)}", 1, 0)
		when "AEHA"
			lcd.drawString(0, 24, "code: #{msg[:code].to_s(16)}", 1, 0)
			lcd.drawString(0, 36, "parity: #{msg[:parity].to_s(16)} data0: #{msg[:data0].to_s(16)}", 1, 0)
			#lcd.drawString(0, 48, "data: #{msg[:data].bytes.collect {|b| b.to_s(16) }.join(" ")}", 1, 0)
			s = ""
			for b in msg[:data].bytes do
				s += b.to_s(16) + " "
			end
			lcd.drawString(0, 48, "data: #{s}", 1, 0)
		when "SIRC"
			lcd.drawString(0, 24, "data: #{msg[:data].to_s(16)}", 1, 0)
			lcd.drawString(0, 36, "addr: #{msg[:address].to_s(16)}", 1, 0)
		end
		t = 0
	elsif ((t >= 5000) && (t % 1000) == 0)
		lcd.fillRect(0, 12, lcd.width, lcd.height - 12, 0)
		lcd.drawString(0, 12, "#{(t / 1000).to_s}秒間 検出出来ませんでした。", 1, 0)
	end

	delay(100)
	t += 100
end

lcd.fillRect(0, 12, lcd.width, lcd.height - 12, 0)
lcd.drawString(0, 12, "#{(t / 1000).to_s}秒間 検出出来ませんでした。", 1, 0)
