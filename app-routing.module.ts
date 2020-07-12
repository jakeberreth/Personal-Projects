import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { PracticeComponent } from './practice/practice.component';
import { AboutComponent } from './about/about.component';
import { ResourcesComponent } from './resources/resources.component';
import { LoginComponent } from './login/login.component';
import { DailyPracticeComponent } from './daily-practice/daily-practice.component';
import { ChallengesComponent } from './challenges/challenges.component';
import { ProgressPageComponent } from './progress-page/progress-page.component';

const routes: Routes = [
  { path: 'home', component: HomeComponent },
  { path: 'about', component: AboutComponent },
  { path: 'practice', component: PracticeComponent},
  { path: 'resources', component: ResourcesComponent },
  { path: 'login', component: LoginComponent },
  { path: 'daily-practice', component: DailyPracticeComponent },
  { path: 'challenges', component: ChallengesComponent },
  { path: 'progress-page', component: ProgressPageComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})

export class AppRoutingModule { }
