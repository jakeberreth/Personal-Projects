import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { NoopAnimationsModule } from '@angular/platform-browser/animations';
import { AppRoutingModule } from './app-routing.module';

import { AppComponent } from './app.component';
import { NavBarComponent } from './nav-bar/nav-bar.component';
import { HomeComponent } from './home/home.component';
import { PracticeComponent } from './practice/practice.component';
import { AboutComponent } from './about/about.component';
import { ResourcesComponent } from './resources/resources.component';
import { LoginComponent } from './login/login.component';
import { DailyPracticeComponent } from './daily-practice/daily-practice.component';
import { ChallengesComponent } from './challenges/challenges.component';

import { MatCardModule } from '@angular/material/card';
import { MatToolbarModule } from '@angular/material/toolbar';
import { MatButtonModule } from '@angular/material/button';
import { MatIconModule } from '@angular/material/icon';
import { FlexLayoutModule } from '@angular/flex-layout';
import { MatCheckboxModule } from '@angular/material/checkbox';
import { MatFormFieldModule } from '@angular/material/form-field';
import { ProgressPageComponent } from './progress-page/progress-page.component';

@NgModule({
  declarations: [
    AppComponent,
    NavBarComponent,
    HomeComponent,
    PracticeComponent,
    AboutComponent,
    ResourcesComponent,
    LoginComponent,
    DailyPracticeComponent,
    ChallengesComponent,
    ProgressPageComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    NoopAnimationsModule,
    MatCardModule,
    MatToolbarModule,
    MatButtonModule,
    MatIconModule,
    FlexLayoutModule,
    MatCheckboxModule,
    MatFormFieldModule,
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
