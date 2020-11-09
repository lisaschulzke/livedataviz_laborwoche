# livedataviz_laborwoche

## Einrichten eines MQTT-brokers:
1. auf Node MQTT out auswählen und unter Server konfigurieren (als Server einen MQTT broker hinzufügen)
2. ein topic hinzufügen (dieses Topic ist wichtig für das Empfangen von Daten durch den MQTT broker)
3. Im Reiter sciherheit den Nutzernamen try und als Passwort try nutzen

# CLient und WebSocketServer wird benötigt
1. Client ist Timestamp mit MQTT out --> timestamp simuliert den Input des Arduinos
2. WebSocketServer ist Websocket in , mit function zu Websocket out, um Mqtt einzubinden, muss mqtt in zu der function gehen
