from fastapi import FastAPI
from transformers import pipeline
app = FastAPI()

# Cargamos un modelo ligero de análisis de sentimiento
classifier = pipeline("sentiment-analysis", model="distilbert-base-uncased-finetuned-sst-2-english")

@app.get("/analizar")
def analizar_texto(texto: str):
    resultado = classifier(texto)
    return {"resultado": resultado}