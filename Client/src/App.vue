<template>
<v-app id="AMCApp">
    <v-navigation-drawer v-if="appIsReady" v-model="ShowDrawer" clipped :clipped-left="$vuetify.breakpoint.lgAndUp" disable-resize-watcher app>
        <v-list dense>
            <template v-for="item in Application.AppContent.MenuItems">
                <v-list-group v-if="item.children" :key="item.caption" v-model="item.model" :prepend-icon="item.model ? item.icon : item['icon-alt']">
                    <template v-slot:activator>
                        <v-list-item-content>
                            <v-list-item-title v-on:click.stop="Application.changePage(item.targetpage)">
                                {{ item.caption }}
                            </v-list-item-title>
                        </v-list-item-content>
                    </template>

                    <v-list-item v-for="(child, i) in item.children" :key="i" link v-on:click.stop="Application.changePage(child.targetPage)">
                        <v-list-item-action v-if="child.icon">
                            <v-icon>{{ child.icon }}</v-icon>
                        </v-list-item-action>
                        <v-list-item-content>
                            <v-list-item-title>
                                {{ child.text }}
                            </v-list-item-title>
                        </v-list-item-content>
                    </v-list-item>
                </v-list-group>

                <v-list-item v-else :key="item.caption" link v-on:click.stop="Application.changePage(item.targetpage)">
                    <v-list-item-action>
                        <v-icon>{{ item.icon }}</v-icon>
                    </v-list-item-action>
                    <v-list-item-content>
                        <v-list-item-title>
                            {{ item.caption }}
                        </v-list-item-title>
                    </v-list-item-content>
                </v-list-item>
            </template>
        </v-list>
    </v-navigation-drawer>

    <v-app-bar app color="primary" dark v-if="appIsReady" :clipped-left="$vuetify.breakpoint.lgAndUp">
        <v-app-bar-nav-icon v-on:click.stop="uiToggleDrawer" />
        <v-btn tile large color="primary" dark v-on:click.stop="Application.changePage(Application.AppDefinition.MainPage)">
            {{ uiButtonCaptionCheck(Application.AppDefinition.TextApplicationName) }}
        </v-btn>

        <v-spacer />

        <template v-for="toolbaritem in Application.AppContent.ToolbarItems">
            <v-btn :key="toolbaritem.id" color="primary" large v-on:click.stop="Application.changePage(toolbaritem.targetpage)">
                <v-icon left>{{ toolbaritem.icon }}</v-icon>{{ uiButtonCaptionCheck(toolbaritem.caption) }}
            </v-btn>
        </template>
    </v-app-bar>

    <v-main>
        <v-container class="fill-height" fluid v-if="appIsLoading">
            <v-row align="center" justify="center">
                <v-progress-circular :value="20" indeterminate></v-progress-circular>
            </v-row>
        </v-container>

        <v-container class="fill-height" fluid v-if="appIsLogin">
			<Dialog_Login :Application="Application" />
        </v-container>
		
		<v-container class="fill-height" fluid v-if="appIsError">
			<Dialog_Error :Application="Application" />
        </v-container>		

		<template v-for="uiPage in Application.AppContent.Pages">
			<v-container :key="uiPage.name" v-if="appIsReady && (Application.AppState.activePage == uiPage.name)" style="width:100%; height:85vh; display:block">
								
				<template v-for="uiModule in uiPage.modules">
					<Module_Content :key="uiModule.name" v-if="(uiModule.type == 'content')" :module="uiModule" :Application="Application" />					
					<Module_Tabs :key="uiModule.name" v-if="(uiModule.type == 'tabs')" :module="uiModule" :Application="Application" />							
					<Module_VerticalSplit :key="uiModule.name" v-if="(uiModule.type == 'verticalsplit')" :module="uiModule" :Application="Application" />							
					<Module_HorizontalSplit :key="uiModule.name" v-if="(uiModule.type == 'horizontalsplit')" :module="uiModule" :Application="Application" />							
				</template>										
						
			</v-container>		
		</template>
        
    </v-main>

    <v-footer color="primary" class="text-right" min-height="30" app >
        <v-spacer />
        <span class="caption white--text" v-if="appHasInformation">&copy; {{ Application.AppDefinition.TextCopyRight }}</span>		
    </v-footer>
	
</v-app>
</template>

<script>

	import AMCApplication from "./Application.js"
	
	import Dialog_Login from "./Dialog_Login.vue";
	import Dialog_Error from "./Dialog_Error.vue";
	
	import Module_Content from "./Module_Content.vue";
	import Module_Tabs from "./Module_Tabs.vue";
	import Module_VerticalSplit from "./Module_VerticalSplit.vue";
	import Module_HorizontalSplit from "./Module_HorizontalSplit.vue";
	
	export default {

		created() {
			this.GlobalTimer = setInterval(this.uiOnTimer, 600);
			
			var baseURL = "/api";
			if (process.env.NODE_ENV === "development") {
				baseURL = "http://localhost:8869/api";
			}
			
			this.Application = new AMCApplication (baseURL);
			this.Application.retrieveConfiguration();
		},
		

		beforeDestroy() {
			if (this.GlobalTimer) {
				clearInterval(this.GlobalTimer);
			}
		},

		computed: {
			appIsLoading() {
				if (!this.Application)
					return false;

				if (!this.Application.AppState)
					return false;

				return this.Application.AppState.currentStatus === "initial";
			},

			appIsLogin() {
				if (!this.Application)
					return false;

				if (!this.Application.AppState)
					return false;
					
				return this.Application.AppState.currentStatus === "login";
			},

			appIsReady() {
				if (!this.Application)
					return false;

				if (!this.Application.AppState)
					return false;

				return this.Application.AppState.currentStatus === "ready";
			},

			appIsError() {
				if (!this.Application)
					return false;

				if (!this.Application.AppState)
					return false;

				return this.Application.AppState.currentStatus === "error";
			},

			appHasInformation() {
				if (!this.Application)
					return false;

				if (!this.Application.AppState)
					return false;

				return (this.Application.AppState.currentStatus === "login") || (this.Application.AppState.currentStatus === "ready");
			} 
		},
		
		components: {
			Dialog_Login,
			Dialog_Error,
			Module_Content,
			Module_Tabs,
			Module_VerticalSplit,
			Module_HorizontalSplit
		},	

		methods: {
			


			uiButtonCaptionCheck(caption) {
				var size = this.$vuetify.breakpoint.name;
				if (size == "xs" || size == "sm") return "";

				return caption;
			},
			
			
			uiToggleDrawer() {
				this.ShowDrawer = !this.ShowDrawer;
			},
								
				
			uiOnTimer() {
				if (this.Application) {
					this.Application.updateContentItems ();			
				}													
			}
						
		},

		data: () => ({
		
			Application: null,
			GlobalTimer: null,
			ShowDrawer: true,
		
		})
	};
</script>

