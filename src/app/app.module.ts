import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouteReuseStrategy } from '@angular/router';

import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import { getFirestore, provideFirestore } from '@angular/fire/firestore';
import { environment } from '../environments/environment'; // Importa el entorno

import { IonicModule, IonicRouteStrategy } from '@ionic/angular';

import { AppComponent } from './app.component';
import { AppRoutingModule } from './app-routing.module';
import { getAuth, provideAuth } from '@angular/fire/auth';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule, IonicModule.forRoot(), 
    AppRoutingModule, 
    provideFirebaseApp(() => initializeApp(environment.firebase)),
    provideFirestore(() => getFirestore()),
    provideFirebaseApp(() => initializeApp({"projectId":"iot-ionic-9e800","appId":"1:385144609748:web:614d4dda54e2ae07bc5441","storageBucket":"iot-ionic-9e800.appspot.com","apiKey":"AIzaSyCyZitMUTuDAaClzBZMsvG64D2qUfegrYM","authDomain":"iot-ionic-9e800.firebaseapp.com","messagingSenderId":"385144609748"})),
    provideFirebaseApp(() => initializeApp({"projectId":"iot-ionic-9e800","appId":"1:385144609748:web:854d32c6a424e75fbc5441","storageBucket":"iot-ionic-9e800.appspot.com","apiKey":"AIzaSyCyZitMUTuDAaClzBZMsvG64D2qUfegrYM","authDomain":"iot-ionic-9e800.firebaseapp.com","messagingSenderId":"385144609748"})),
    provideAuth(() => getAuth())],
  providers: [{ provide: RouteReuseStrategy, useClass: IonicRouteStrategy }],
  bootstrap: [AppComponent],
})
export class AppModule {}
